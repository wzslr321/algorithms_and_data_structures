// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

func search(nums []int, target int) int {
	n := len(nums)
	if n == 1 {
		if nums[0] == target {
			return 0
		}
		return -1
	}
	low, high := 0, n-1

	pivot := -1
	for low < high {
		mid := low + (high-low+1)/2

		if nums[mid] > nums[low] {
			low = mid
		} else {
			high = mid - 1
			if nums[mid] < nums[mid-1] {
				pivot = mid
				break
			}
		}
	}

	org := nums
	if pivot != -1 {
		org = nums[pivot:n]
		org = append(org, nums[0:pivot]...)
	}

	low, high = 0, n-1
	for low < high {
		mid := low + (high-low+1)/2

		if target < org[mid] {
			high = mid - 1
		} else {
			low = mid
		}
	}

	if org[low] == target {
		if pivot == -1 {
			return low
		}
		return (low + pivot) % n
	}

	return -1
}