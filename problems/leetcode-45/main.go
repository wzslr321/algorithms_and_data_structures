// https://leetcode.com/problems/jump-game-ii/description/

func jump(nums []int) int {
	currJump, jumps, furthest := 0, 0, 0
	for i := 0; i < len(nums)-1; i++ {
		if i+nums[i] > furthest {
			furthest = i + nums[i]
			if furthest >= len(nums)-1 {
				return jumps + 1
			}
		}

		if i == currJump {
			jumps, currJump = jumps+1, furthest

		}
	}

	return 0
}