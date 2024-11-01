package main

import (
	"fmt"
	"math/rand"
	"sync"
)

// 5个协程并发，发送随机数量的随机数给另外一个协程，求和并打印结果，要求空间复杂度为O(1)。

func sender(chA chan int, wg *sync.WaitGroup) {
	// wg.Done放在defer中
	defer wg.Done()
	num_ := rand.Intn(10)

	for i := 0; i < num_; i++ {
		chA <- rand.Intn(10)
	}
}

func receiver(chA chan int, sum_ *int) {
	for value := range chA {
		*sum_ += value
	}
}

func test_sender_receiver() {
	var wg sync.WaitGroup
	chA := make(chan int, 5)
	var sum_ int = 0

	go receiver(chA, &sum_)

	wg.Add(5) // 如果使用有缓存的channel，可能会因为缓存满了导致asleep, 所以receiver中不能有主动的return
	// 且不能将receiver也纳入wg.Wait的范围，因为receiver需要等待 chA 关闭才会调用wg.Done, 会出现死锁
	for i := 0; i < 5; i++ {
		go sender(chA, &wg)
	}

	wg.Wait()
	close(chA)
	fmt.Printf("channel closed, the sum_ is %d\n", sum_)
}

//func main() {
//	test_sender_receiver()
//}
