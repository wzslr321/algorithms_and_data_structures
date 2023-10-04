// https://leetcode.com/problems/zigzag-conversion/description/

func convert(s string, numRows int) string {
	rows := make([]string, numRows) 
	n, i := len(s), 0
 
	for i < n {
		for j := 0; j < numRows && i < n; j++ {
			rows[j] += string(s[i])
			i++
		}
		for j := numRows - 2; j >= 1 && i < n; j-- {
			rows[j] += string(s[i])
			i++
		}
	}
	ans := ""
	for _, v := range(rows) {
		ans += v
	}
	return ans
 }