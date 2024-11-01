package main

// 数据到达100个就发送，如果超过了一定时间还没到100个，也发送掉

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// 使用time.Ticker来控制时间
// 使用channel + buffer来控制数据的积累 和 批量发送

// 常量定义
const (
	batchSize   = 100
	maxWaitTime = 5 * time.Second
)

func batchSender(batch []int) {
	fmt.Printf("Sending batch: %v\n", batch)
}

func batchProcessor(datach chan int, wg *sync.WaitGroup) {
	defer wg.Done()

	var batch []int
	timer := time.NewTimer(maxWaitTime) // 超时监控
	for {
		select {
		case data, ok := <-datach:
			// channel closed
			if !ok {
				if len(batch) > 0 {
					batchSender(batch)
				}
				return
			}
			batch = append(batch, data)
			if len(batch) == batchSize {
				batchSender(batch)
				batch = []int{} // 清空
			}
		case <-timer.C: // 超时
			if len(batch) > 0 {
				batchSender(batch)
			}
			batch = []int{}
			timer.Reset(maxWaitTime)
		}
	}
}

func test_batchProcessor() {
	var wg sync.WaitGroup
	datach := make(chan int)

	wg.Add(1)
	go batchProcessor(datach, &wg)

	// 模拟输入
	for i := 0; i < 250; i++ {
		datach <- rand.Intn(1000)
		time.Sleep(time.Duration(rand.Intn(50)) * time.Millisecond) // 模拟数据发送
	}

	close(datach)
	wg.Wait()
}

//func main() {
//	test_batchProcessor()
//}
