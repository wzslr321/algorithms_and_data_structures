// https://leetcode.com/problems/gas-station/description/

func canCompleteCircuit(gas []int, cost []int) int { 
	n := len(cost)
	totalGas, totalCost := 0, 0
	currGas, start := 0, 0
	for i := 0; i < n; i++ {
		totalGas += gas[i]
		totalCost += cost[i]
 
		currGas += gas[i] - cost[i]
 
		if currGas < 0 {
			start, currGas = i + 1, 0
		}
	} 
	if totalGas < totalCost {
		return -1
	}
 
	return start
 }