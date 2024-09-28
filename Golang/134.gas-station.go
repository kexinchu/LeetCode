package leetcode

func canCompleteCircuit(gas []int, cost []int) int {
	var roadDis int = len(gas)
	var totalGas, totalCost, curGas, startingPos int // default is 0

	for pos := 0; pos < roadDis; pos++ {
		totalGas += gas[pos]
		totalCost += cost[pos]
		curGas += (gas[pos] - cost[pos])

		if curGas < 0 {
			curGas = 0
			startingPos = pos + 1
		}
	}

	if totalGas < totalCost {
		return -1
	}
	return startingPos
}
