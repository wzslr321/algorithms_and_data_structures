// https://leetcode.com/problems/sliding-window-maximum/description/

func maxSlidingWindow(nums []int, k int) []int {
	deque := make([]int, 0)
	for i := 0; i < k; i++ {
		for len(deque) > 0 && nums[i] >= nums[deque[len(deque)-1]] {
			deque = deque[:len(deque)-1]
		}
		deque = append(deque, i)
	}
	ans := make([]int, 0)
	ans = append(ans, nums[deque[0]])

	for i := k; i < len(nums); i++ {
		if deque[0] == i-k {
			deque = deque[1:]
		}
		for len(deque) > 0 && nums[i] >= nums[deque[len(deque)-1]] {
			deque = deque[:len(deque)-1]
		}
		deque = append(deque, i)
		ans = append(ans, nums[deque[0]])
	}

	return ans
}