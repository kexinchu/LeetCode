package main

import (
	"math"
)

/*
每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
0 <= j <= nums[i]
i + j < n
*/

func jump(nums []int) int {
	length := len(nums)
	if length <= 1 {
		return 0
	}

	end := 0
	maxPosition := 0
	steps := 0
	for i := 0; i < length-1; i++ {
		maxPosition = max(maxPosition, i+nums[i])

		// early stop
		if maxPosition >= length-1 {
			return steps + 1
		}

		if i == end {
			end = maxPosition
			steps++
		}
	}
	return -1
}

func jump_with_footprint(nums []int) (int, []int) {
	n := len(nums)
	dist := make([]int, n) // reach this position, the smallest skip steps
	prev := make([]int, n) // the previous position
	for i := range dist {
		dist[i] = math.MaxInt32
		prev[i] = -1
	}
	dist[0] = 0
	maxReach := 0
	for i := 0; i <= maxReach && i < n; i++ {
		if i+nums[i] > maxReach {
			furthest := min(n-1, i+nums[i])
			// maxReach is the furthest position for last position;
			// this iteration means we can go further with current position
			for j := max(maxReach+1, i+1); j <= furthest; j++ {
				// update the smallest steps
				if dist[j] > dist[i]+1 {
					dist[j] = dist[i] + 1
					prev[j] = i
				}
			}
			maxReach = furthest
		}
		if maxReach >= n-1 {
			break
		}
	}

	if dist[n-1] == math.MaxInt32 {
		return -1, nil
	}

	// Reconstruct path
	path := []int{}
	index := n - 1
	for index != -1 {
		path = append([]int{index}, path...)
		index = prev[index]
	}

	return dist[n-1], path
}

//func main() {
//	fmt.Println(jump([]int{2, 3, 1, 0, 4}))
//	fmt.Println(jump([]int{2, 3, 1, 0, 4, 2, 3, 1, 0, 4}))
//	fmt.Println(jump([]int{3, 2, 1, 0, 4}))
//	fmt.Println(jump([]int{3}))
//}
