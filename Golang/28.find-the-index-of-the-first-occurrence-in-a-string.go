package leetcode

func strStr(haystack string, needle string) int {
	if len(haystack) < len(needle) {
		return -1
	}
	var start int = 0
	var needPos int = 0
	for start <= len(haystack)-len(needle) {
		if haystack[start] == needle[needPos] {
			var i int = 0
			for i < len(needle) && haystack[start+i] == needle[needPos+i] {
				i += 1
			}
			if i == len(needle) {
				return start
			}
		}
		start += 1
	}
	return -1
}
