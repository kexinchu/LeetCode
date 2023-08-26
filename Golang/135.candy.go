package leetcode

func candy(ratings []int) int {
    var ratLen int = len(ratings)
    if ratLen == 0 {
        return 0
    }
    // init
    var numCandies int = ratLen
    var candies []int = make([]int, ratLen)
    for i := 0; i < ratLen; i++ {
        candies[i] = 1;
    }
    // from left to right
    for i := 1; i < ratLen; i++ {
        if ratings[i] > ratings[i-1] {
            numCandies += (candies[i-1] + 1 - candies[i])
            candies[i] = candies[i-1] + 1
        }
    }
    // from right 2 left
    for i := ratLen - 2; i >= 0; i-- {
        if ratings[i] > ratings[i+1] && candies[i] <= candies[i+1] {
            numCandies += (candies[i+1] + 1 - candies[i])
            candies[i] = candies[i+1] + 1
        }
    }
    return numCandies
}