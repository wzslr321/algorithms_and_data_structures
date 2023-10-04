// https://leetcode.com/problems/h-index/description/

func hIndex(citations []int) int {
	count := make([]int, 1001) 
	for _, v := range(citations) {
		 count[v]++
	}
 
	n := len(count) 
	for i := n - 1; i > 0; i-- {
	   count[i - 1] += count[i] 
	}
 
	ans := 0
	for _, v := range(citations) {
		 ans = max(ans, min(count[v], v))
	}
 
	return ans
 }
 
 func max(a, b int) int {
	 if a > b {
		 return a
	 }
	 return b
 }
 
 func min(a, b int) int {
	 if a < b {
		 return a
	 }
	 return b
 }