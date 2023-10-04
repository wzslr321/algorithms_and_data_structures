// https://leetcode.com/problems/reverse-words-in-a-string/description/

func reverseWords(s string) string {
	filtered := make([]rune, 0, len(s))

	for i, ch := range s {
		if ch != ' ' || (i > 0 && s[i-1] != ' ') {
			filtered = append(filtered, ch)
		}
	}
	n := len(filtered)
	if filtered[n-1] == ' ' {
		filtered = filtered[:n-1]
		n--
	}

	ans := make([]string, 0, len(filtered))
	last := n
	for i := range filtered {
		if filtered[n-1-i] == ' ' {
			ans = append(ans, string(filtered[n-1-i:last]))
			last = n - 1 - i
		}
		if n-i-1 == 0 {
			ans = append(ans, " "+string(filtered[n-1-i:last]))
		}
	}

	ans[0] = ans[0][1:]
	return strings.Join(ans, "")
}