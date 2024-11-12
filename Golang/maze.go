package main

import (
	"container/heap"
	"fmt"
	"math"
)

/*
迷宫问题解题思路
1，两点间是否能到达，使用dfs
2，求最短路径，使用bfs
3，如果路径带权重，使用Dijkstra
*/

// dfs - 递归算法
// 200.岛屿数量

var Bias = [][2]int{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
}

func dfs_island(grid [][]byte, row, col, nrow, ncol int, visited [][]bool) {
	// 从1的位置开始检索，并将检索过的值复写成0; if 已经是0了，探索到边界，返回
	visited[row][col] = true
	if grid[row][col] == '0' {
		return
	}
	grid[row][col] = '0'
	// explore the nearest point
	for _, bias := range Bias {
		point := [2]int{row + bias[0], col + bias[1]}
		if point[0] >= 0 && point[0] < nrow && point[1] >= 0 && point[1] < ncol {
			if visited[point[0]][point[1]] == true {
				continue
			}
			dfs_island(grid, point[0], point[1], nrow, ncol, visited)
		}
	}
}
func numIslands(grid [][]byte) int {
	nrow := len(grid)
	if nrow < 1 {
		return 0
	}
	ncol := len(grid[0])

	visited := make([][]bool, nrow)
	for i := 0; i < nrow; i++ {
		visited[i] = make([]bool, ncol)
	}
	num_island := 0
	for i := 0; i < nrow; i++ {
		for j := 0; j < ncol; j++ {
			if grid[i][j] == '1' {
				num_island += 1
				dfs_island(grid, i, j, nrow, ncol, visited)
			} else {
				visited[i][j] = true
			}
		}
	}
	return num_island
}

// bfs -
// queue + dp数组记录从start点走到每个point的步长
type Node struct {
	point [2]int
	steps int
}

func bfs(maze [][]byte, start, end [2]int) int {
	nrow := len(maze)
	if nrow < 1 {
		return 0
	}
	ncol := len(maze[0])

	// 创建一个访问标记的二维切片，初始化为 false
	visited := make([][]bool, nrow)
	for i := range visited {
		visited[i] = make([]bool, ncol)
	}

	// 借助queue来存储当前点
	queue := []Node{{start, 0}}
	visited[start[0]][start[1]] = true

	// start BFS
	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]

		// 找到
		if current.point[0] == end[0] && current.point[1] == end[1] {
			return current.steps
		}

		for _, bias := range Bias {
			point := [2]int{current.point[0] + bias[0], current.point[1] + bias[1]}
			if point[0] >= 0 && point[0] < nrow && point[1] >= 0 && point[1] < ncol {
				// visited and 墙
				if visited[point[0]][point[1]] == true || maze[point[0]][point[1]] == '1' {
					continue
				}
				visited[point[0]][point[1]] = true
				queue = append(queue, Node{point, current.steps + 1})
			}
		}
	}

	// 如果无法抵达终点
	return -1
}

func Test_Bfs() {
	// 示例迷宫，0 表示通路，1 表示墙
	maze := [][]byte{
		{'0', '0', '1', '0'},
		{'1', '0', '1', '0'},
		{'0', '0', '0', '1'},
		{'0', '1', '0', '0'},
	}

	// 定义入口和出口
	start := [2]int{0, 0} // 起点坐标
	end := [2]int{3, 3}   // 终点坐标

	// 调用 BFS 函数
	steps := bfs(maze, start, end)

	if steps != -1 {
		fmt.Printf("最短路径长度为：%d\n", steps)
	} else {
		fmt.Println("无法到达终点")
	}
}

// Dijkstra 算法，适用于加权有向/无向图，要求图中边的权重为非负值
// 实现： 单独的queue不在适用了，需要使用priority_queue （heap）, 优先选择权重节点小的节点

type NodeN struct {
	point [2]int
	costs float64
	index int // heap接口需要
}

// 实现heap接口的优先队列
type PriorityQueue []*NodeN

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].costs < pq[j].costs
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	node := x.(*NodeN)
	node.index = n
	*pq = append(*pq, node)
}

func (pq *PriorityQueue) Pop() interface{} {
	// heap顶弹出
	old := *pq
	n := len(old)
	node := old[n-1]
	node.index = -1
	*pq = old[0 : n-1]
	return node
}

func dijkstra(maze [][]byte, weights [][]float64, start, end [2]int) float64 {
	nrow := len(maze)
	if nrow < 1 {
		return 0
	}
	ncol := len(maze[0])
	visited := make([][]bool, nrow)

	// 初始化距离矩阵
	dist := make([][]float64, nrow)
	for i := 0; i < nrow; i++ {
		dist[i] = make([]float64, ncol)
		for j := 0; j < ncol; j++ {
			dist[i][j] = math.Inf(1)
		}
	}
	dist[start[0]][start[1]] = weights[start[0]][start[1]]
	visited[start[0]][start[1]] = true

	// 创建优先队列
	pq := &PriorityQueue{}
	heap.Init(pq)
	heap.Push(pq, &NodeN{point: start, costs: weights[start[0]][start[1]]})

	// 遍历
	for pq.Len() > 0 {
		current := heap.Pop(pq).(*NodeN)
		currentPoint := current.point

		// 找到
		if currentPoint[0] == end[0] && currentPoint[1] == end[1] {
			return current.costs
		}

		for _, bias := range Bias {
			point := [2]int{currentPoint[0] + bias[0], currentPoint[1] + bias[1]}
			if point[0] >= 0 && point[0] < nrow && point[1] >= 0 && point[1] < ncol {
				if visited[point[0]][point[1]] == true || maze[point[0]][point[1]] == '1' {
					continue
				}
				visited[point[0]][point[1]] = true
				newCost := current.costs + weights[point[0]][point[1]]
				// 找到更小的路径，update costs
				if newCost < dist[point[0]][point[1]] {
					dist[point[0]][point[1]] = newCost
					heap.Push(pq, &NodeN{point: point, costs: newCost})
				}
			}
		}
	}
	// 没有路径
	return -1
}
