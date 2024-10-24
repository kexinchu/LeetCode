package main

/*
*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
func productExceptSelf(nums []int) []int {
	numsLen := len(nums)
	prefixProduct := make([]int, numsLen)

	prefixProduct[0] = 1
	for i := 1; i < numsLen; i++ {
		prefixProduct[i] = prefixProduct[i-1] * nums[i-1]
	}

	suffix := nums[numsLen-1]
	for idx := numsLen - 2; idx >= 0; idx-- {
		prefixProduct[idx] = prefixProduct[idx] * suffix
		suffix = suffix * nums[idx]
	}
	return prefixProduct
}
