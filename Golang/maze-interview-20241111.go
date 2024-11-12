package main

import (
	"fmt"
)

var directions = map[byte][]int{
	'N': {-1, 0},
	'S': {1, 0},
	'E': {0, 1},
	'W': {0, -1},
}

func canEscape(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	visited := make([][]bool, m)
	for i := range visited {
		visited[i] = make([]bool, n)
	}

	// Mark cells affected by fire
	fire := make([][]bool, m)
	for i := range fire {
		fire[i] = make([]bool, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'E' || grid[i][j] == 'W' {
				// Mark the dragon's position as affected by fire
				fire[i][j] = true

				dx, dy := directions[grid[i][j]][0], directions[grid[i][j]][1]
				x, y := i+dx, j+dy
				for x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '.' {
					fire[x][y] = true
					x += dx
					y += dy
				}
			}
		}
	}
	for i := 0; i < m; i++ {
		fmt.Println(fire[i])
	}

	// Start exploring from (0,0)
	return dfs(0, 0, m, n, visited, fire)
}

func dfs(x, y, m, n int, visited, fire [][]bool) bool {
	if x == m-1 && y == n-1 {
		return true
	}

	if x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || fire[x][y] {
		return false
	}

	visited[x][y] = true

	directions := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for _, d := range directions {
		if dfs(x+d[0], y+d[1], m, n, visited, fire) {
			return true
		}
	}

	visited[x][y] = false
	return false
}

func main() {
	grid := [][]byte{
		{'.', '.', '.', 'E', '.'},
		{'.', 'N', '.', '.', '.'},
		{'.', '.', '.', 'S', '.'},
		{'S', '.', '.', 'W', '.'},
	}

	if canEscape(grid) {
		fmt.Println("Xiaoming can escape!")
	} else {
		fmt.Println("Xiaoming cannot escape.")
	}
}
