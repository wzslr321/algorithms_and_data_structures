// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	
	left, right := 0, nums[len(nums)-1] - nums[0]
	
	for left < right {
		mid := (left + right) / 2
		if canFormPairs(nums, mid, p) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	
	return left
}

func canFormPairs(nums []int, mid int, p int) bool {
	count := 0
	for i := 0; i < len(nums) - 1 && count < p; {
		if nums[i+1] - nums[i] <= mid {
			count++
			i += 2
		} else {
			i++
		}
	}
	return count >= p
}