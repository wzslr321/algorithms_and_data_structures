// https://leetcode.com/problems/trapping-rain-water/description/

func trap(height []int) int {
	ans, n := 0, len(height)

	maxL := make([]int, n)
	maxR := make([]int, n)
	l, r := 0, 0

	maxL[0] = 0
	maxR[n-1] = 0
	for i := 1; i < n; i++ {
		if height[i-1] > l {
			l = height[i-1]
		}
		if height[n-i] > r {
			r = height[n-i]
		}
		maxL[i] = l
		maxR[n-i-1] = r
	}

	for i, v := range height {
		min := maxL[i]
		if maxR[i] < min {
			min = maxR[i]
		}

		if min-v > 0 {
			ans += min - v
		}
	}

	return ans
}