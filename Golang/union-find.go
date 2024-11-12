package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

/*
朋友圈问题
现在有 105 个用户，编号为0-104； 现在已知有m对关系，每一对关系给你两个数x和y，代表编号x和编号为y的用户在一个圈子里，
现在请写两个程序：1，判断有多少个圈子；2，获取用户最多的那个圈子
*/

// 并查集结构体
type UnionFind struct {
	parent []int
	size   []int
}

// init
func NewUnionFind(num int) *UnionFind {
	parent := make([]int, num)
	size := make([]int, num)
	for i := 0; i < num; i++ {
		parent[i] = i
		size[i] = 1
	}
	return &UnionFind{parent, size}
}

// find the root, 带路径压缩
func (uf *UnionFind) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x])
	}
	return uf.parent[x]
}

// 合并集合
func (uf *UnionFind) Union(x, y int) {
	rootX := uf.Find(x)
	rootY := uf.Find(y)
	// join
	if rootX != rootY {
		uf.parent[rootY] = rootX
		uf.size[rootX] += uf.size[rootY]
	}
}

// 获取Union大小
func (uf *UnionFind) GetSize(x int) int {
	rootX := uf.Find(x)
	return uf.size[rootX]
}

// 计算有多少个圈子
func countCircles(n int, pairs [][2]int) int {
	uf := NewUnionFind(n)
	for _, pair := range pairs {
		uf.Union(pair[0], pair[1])
	}
	circleSet := make(map[int]int)
	for i := 0; i < n; i++ {
		root := uf.Find(i)
		if _, ok := circleSet[root]; !ok {
			circleSet[root] = uf.GetSize(i)
		}
	}
	return len(circleSet)
}

// 获取用户最多的圈子
func largestCircle(n int, pairs [][2]int) int {
	uf := NewUnionFind(n)
	for _, pair := range pairs {
		uf.Union(pair[0], pair[1])
	}
	maxSize := 0
	for i := 0; i < n; i++ {
		size := uf.GetSize(i)
		if size > maxSize {
			maxSize = size
		}
	}
	return maxSize
}

func Test() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("请输入用户数量 N 和关系数量 M（以空格分隔）：")
	line, _ := reader.ReadString('\n')
	nums := strings.Fields(line)
	n, _ := strconv.Atoi(nums[0])
	m, _ := strconv.Atoi(nums[1])

	pairs := make([][2]int, m)
	fmt.Println("请输入每对关系 x 和 y（每行一对）：")
	for i := 0; i < m; i++ {
		line, _ := reader.ReadString('\n')
		nums = strings.Fields(line)
		x, _ := strconv.Atoi(nums[0])
		y, _ := strconv.Atoi(nums[1])
		pairs[i] = [2]int{x, y}
	}

	fmt.Println("圈子的数量是：", countCircles(n, pairs))
	fmt.Println("用户数量最多的圈子包含用户数：", largestCircle(n, pairs))
}

/*
请输入用户数量 N 和关系数量 M（以空格分隔）：
5 3
请输入每对关系 x 和 y（每行一对）：
0 1
1 2
3 4
圈子的数量是： 2
用户数量最多的圈子包含用户数： 3
*/
