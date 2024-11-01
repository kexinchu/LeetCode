package main

/*
给你一个整数数组 nums，请你将该数组升序排列。
你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]

提示：
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

import (
	"fmt"
	"math/rand/v2"
)

func quick_sort_partition(arr []int, left int, right int) {
	if right <= left {
		return
	}
	// random select the pivot
	pivot := left + rand.IntN(right-left+1)
	// exchange left with pivot
	arr[pivot], arr[left] = arr[left], arr[pivot]

	i, j := left, right
	for i < j {
		for i < j && arr[j] >= arr[left] {
			j -= 1
		}
		for i < j && arr[i] <= arr[left] {
			i += 1
		}
		// exchange
		if i < j {
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	// exchange the left with j
	arr[left], arr[j] = arr[j], arr[left]
	// exchange left with i
	quick_sort_partition(arr, left, j-1)
	quick_sort_partition(arr, j+1, right)
}

func sortArray(nums []int) []int {
	right := len(nums) - 1
	if right < 0 {
		fmt.Println("empty array nums")
	}
	quick_sort_partition(nums, 0, right)
	return nums
}

//func main() {
//	nums := []int{110, 100, 0}
//	fmt.Println(sortArray(nums))
//
//	nums = []int{3, 2, 1, 5, 6, 4}
//	fmt.Println(sortArray(nums))
//
//	nums = []int{5, 1, 1, 2, 0, 0}
//	fmt.Println(sortArray(nums))
//
//	nums = []int{3, 2, 3, 1}
//	fmt.Println(sortArray(nums))
//}
