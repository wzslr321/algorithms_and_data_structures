// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

func search(nums []int, target int) bool {
	n := len(nums)

	if n == 0 {
		return false
	}

	low, high := 0, n - 1
	for low <= high {
		for low < high && nums[low]	== nums[low + 1] {
			low++
		}
		for low < high && nums[high]	== nums[high - 1] {
			high--
		}

		mid := low + (high - low) / 2
		if nums[mid] == target {
				return true
		}

		if nums[mid] >= nums[low] {
    // there was no pivot yet - we are in the "first array"
			// range found, narrow it
			if target >= nums[low] && target < nums[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}

		} else {
	  // pivot was spotted \U0001f633 - we are in the "second array"
			// range found, narrow it
			if target <= nums[high] && target > nums[mid] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}
	return false
}