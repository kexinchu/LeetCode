package main

import (
	"fmt"
	"sync"
)

func printA(chA, chB chan bool, wg *sync.WaitGroup) {
	defer wg.Done()
	i := 0
	for {
		_, ok := <-chA // wait for signal
		if !ok {
			return
		}
		if i < 10 {
			fmt.Println("a")
			i++
			chB <- true
		} else {
			close(chB)
			return
		}
	}
}

func printB(chA, chB chan bool, wg *sync.WaitGroup) {
	defer wg.Done()
	i := 0
	for {
		_, ok := <-chB // wait for signal
		if !ok {
			return
		}

		if i < 10 {
			fmt.Println("b")
			i++
			chA <- true
		} else {
			close(chA)
			return
		}
	}
}

func test_print_channel() {

	var wg sync.WaitGroup

	chA := make(chan bool, 1)
	chB := make(chan bool, 1)

	wg.Add(2)
	go printA(chA, chB, &wg)
	go printB(chA, chB, &wg)

	chA <- true

	wg.Wait()

	fmt.Println("done")
}
