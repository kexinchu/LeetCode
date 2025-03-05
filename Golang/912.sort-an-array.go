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
	"math/rand/v2"
)

func bubbleSort(nums []int) {
	var len_ = len(nums)

	// each iteration, move the biggest val to "correct" pos
	// => (len_ - i - 1, len_ - 1] already sorted
	for i := 0; i < len_-1; i++ {
		var swapped bool = false
		for j := 0; j < len_-i-1; j++ {
			if nums[j] > nums[j+1] {
				nums[j], nums[j+1] = nums[j+1], nums[j]
				swapped = true
			}
		}

		// no swap, means already sorted
		if !swapped {
			break
		}
	}
}

func quickSort(nums []int, left, right int) {
	if left >= right {
		return
	}

	// select benchmark - random
	pivot := left + rand.IntN(right-left+1)
	nums[pivot], nums[left] = nums[left], nums[pivot]
	// iteration: exchange nums[i],nums[j]
	// when nums[i] > nums[left] and nums[j] < nums[left]
	i, j := left, right
	for i < j {
		// last value < nums[left]
		for i < j && nums[j] >= nums[left] {
			j--
		}
		// first value > nums[left]
		for i < j && nums[i] <= nums[left] {
			i++
		}
		if i < j {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	// exchange left with j (the last val < nums[left] after the loop)
	nums[j], nums[left] = nums[left], nums[j]

	quickSort(nums, left, j-1)
	quickSort(nums, j+1, right)
}

func insertionSort(nums []int) {
	// from left to right, make every item in correct place in range [0: i]
	numsLen := len(nums)
	for i := 0; i < numsLen; i++ {
		pivot := nums[i]
		j := i - 1

		for j >= 0 && nums[j] > pivot {
			// 右移
			nums[j+1] = nums[j]
			j -= 1
		}

		nums[j+1] = pivot
	}
}

// heap function
func heapify(nums []int, len int, i int) {
	/* move the biggest val to root (level-order): nums[left]
	 * params: nums array
	 * 		   len the length of nums or sub-nums
	 * 		   i: the index of val (node-val)
	 */
	// initial largest as root： suppose the current i is the biggest one
	largest := i
	left := 2*i + 1  // left child index
	right := 2*i + 2 // right child index

	if left < len && nums[left] > nums[largest] {
		largest = left
	}
	if right < len && nums[right] > nums[largest] {
		largest = right
	}
	if largest != i {
		// swap largest val to root: i
		nums[i], nums[largest] = nums[largest], nums[i]
		// for the sub-tree with "largest" as root, since the val in "largest" is changed,
		// we need re-balance the heap
		heapify(nums, len, largest)
	}
}

func heapSort(nums []int) {
	// use max-heap: the left-/right-node is smaller than the root
	// additional:  min-heap: the root keeps the smallest val

	// step1, treat the nums array as a complete binary tree (level-order)
	// pivot = len(nums)/2; 0 ~ pivot-1 is the left sub-tree
	// while the pivot+1 ~ len(nums) is the right sub-tree

	// step2, build a max-heap, keep the biggest val at the root (nums[0])
	numsLen := len(nums)
	// since the heap is thought as level order, we only need consider all "root" node
	for i := numsLen/2 - 1; i >= 0; i-- {
		heapify(nums, numsLen, i)
	}

	// Step3, sort the array by placing largest element at end of unsorted array
	var last_target_idx = numsLen - 1
	for last_target_idx >= 0 {
		// biggest val is at nums[0] for max-heap - swap
		nums[0], nums[last_target_idx] = nums[last_target_idx], nums[0]
		// rebalance the heap
		heapify(nums, last_target_idx, 0)
		last_target_idx -= 1
	}
}

func sortArray(nums []int) []int {
	// bubbleSort(nums)

	// quickSort(nums, 0, len(nums)-1)

	// insertionSort(nums)

	heapSort(nums)

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
