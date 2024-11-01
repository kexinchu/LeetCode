package main

import "fmt"

func test_slice() {
	s1 := []int{0, 1, 2, 3}
	s2 := s1[1:3]
	fmt.Printf("s2: %v, cap(s2): %d\n", s2, cap(s2)) // 1 {1,2}, 2

	s1[1] = 10
	fmt.Printf("s1: %v, s2: %v\n", s1, s2) // 2 {0, 10, 2, 3}, {10, 2}

	s2 = append(s2, 100)
	s2 = append(s2, 200)
	fmt.Printf("s1: %v, s2: %v\n", s1, s2) // 3 {0, 10, 2, 100} {10, 2, 100, 100}
}
