// https://leetcode.com/problems/group-anagrams/description/

func groupAnagrams(strs []string) [][]string {
	ans := make([][]string, 0)
	seen := make(map[string]int)

	for _, v := range strs {
		letters := make([]int, 26)
		for _, l := range v {
			letters[l-'a']++
		}
		strf := ""
		for i, l := range letters {

			strf += fmt.Sprintf("%c%d", 'a'+i, l)
		}
		i, ok := seen[strf]
		if ok {
			ans[i] = append(ans[i], v)
		} else {
			ans = append(ans, []string{v})
			seen[strf] = len(ans) - 1
		}
	}

	return ans
}