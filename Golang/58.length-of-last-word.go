package leetcode

func lengthOfLastWord(s string) int {
	var sLen int = len(s)
	var pos int = sLen - 1
	// skip the spaces
	for {
		if pos < 0 || s[pos] != ' ' {
			break
		}
		pos -= 1
	}
	var length int = 0
	for {
		if pos < 0 || s[pos] == ' ' {
			break
		}
		pos -= 1
		length += 1
	}
	return length
}
