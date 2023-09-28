// https://leetcode.com/problems/minimum-size-subarray-sum/description/

func minSubArrayLen(target int, nums []int) int {
	ans, value, n := float64(math.MaxInt), 0, len(nums)

	slide := false
	found := false
	for i, start := 0, 0; i < n; i++ {
		value += nums[i]
		if slide {
			value -= nums[start]
			start++
		}

		if value >= target {
			found = true
			window := i - start + 1

			// shrink the window, if nums[i]
			// is so big, that it can reduce some
			// numbers from the front
			for start < i {
				if value-nums[start] >= target {
					window--
					value -= nums[start]
				} else {
					break
				}
				start++
			}

			slide = true
			ans = math.Min(ans, float64(window))
		}
	}

	if !found {
		return 0
	}

	return int(ans)
}