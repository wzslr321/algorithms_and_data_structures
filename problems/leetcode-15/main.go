// https://leetcode.com/problems/3sum/description/

func threeSum(nums []int) [][]int {
	ans := make([][]int, 0, 1000)
	used := make(map[int]bool)
	n := len(nums)

	sort.Ints(nums)
	for i := 0; i < n-2; i++ {
		if used[nums[i]] {
			continue
		}
		l, r, target := i+1, n-1, -nums[i]
		used2 := make(map[int]bool) 
		for l < r {
			if used2[nums[l]] && used2[nums[r]] {
				l++
				continue
			}
			if nums[l]+nums[r] == target {
				ans = append(ans, []int{nums[i], nums[l], nums[r]})
				used[nums[i]] = true
				used2[nums[l]] = true
				used2[nums[r]] = true
				l++
				continue
			} else if nums[l]+nums[r] < target {
				l++
			} else {
				r--
			}
		}
	}

	return ans
}