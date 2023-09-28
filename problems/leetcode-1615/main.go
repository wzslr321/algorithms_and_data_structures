// https://leetcode.com/problems/maximal-network-rank/description/

func maximalNetworkRank(n int, roads [][]int) int {
	graph := make([][]int, n)
	connected := make(map[string]bool, 2 * n)

	for _, road := range roads {
		a := road[0]
		b := road[1]

		connected[fmt.Sprintf("%d-%d", a, b)] = true
		connected[fmt.Sprintf("%d-%d", b, a)] = true
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}

	best, prevBest := -1,-1
	for _, city := range graph {
		if len(city) > best {
			prevBest = best
			best = len(city)
			continue
		}
		if len(city) > prevBest {
			prevBest = len(city)
		}
	}


	psb := make([]int, 0, n)
	for i, city := range graph {
		if len(city) == best || len(city) == prevBest {
			psb = append(psb, i)
		}
	}

	ans := 0
	for i := 0; i < len(psb); i++ {
		for j := i + 1; j < len(psb); j++ {
			a := psb[i]
			b := psb[j]

			if connected[fmt.Sprintf("%d-%d", a, b)] {
				ans = max(ans, len(graph[a])+ len(graph[b])- 1)
			} else {
				ans = max(ans, len(graph[a]) + len(graph[b]))
			}
		}
	}


	return ans
}
func max(a,b int) int {
    if a > b {
        return a
    }
    return b
}