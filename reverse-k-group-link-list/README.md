# chukexin-cpp
简要说明
**固定题目二**【用C/C++实现】K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5
说明 :
* 你的算法只能使用常数的额外空间。
* 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

要求：代码+单测，另附一份简洁、清晰的README.md文档，包括：设计思路、性能测试结果、基本使用说明等；markdown格式书写

## 目录结构
```
├── main.cpp    // 程序入口
├── include		// 头文件
│   ├── reverse_kgroup_list.h   	// 头文件
├── src			// 源文件
│   └── reverse_kgroup_list.cpp		// 源文件
└── unitest		// 单测
│	├── case
│   │ 	├── reverse_kgroup_list_test.cpp
```

## 快速开始
bcloud build
./output/bin/chukexin-cpp

## 测试
./output/test/chukexin-app_test

## 设计思路
假设一个链表 l 的长度为n，k个一组翻转链表 原链表: 1 -> 2 -> 3 -> ... -> n-1 -> n，按组划分即： (1, 2, ... k) -> (k+1, k+2, ... 2k) -> ... ( ..., n)，假设一共有m组 翻转后的链表为：(k, ..., 2, 1) -> (2k, ..., k+2, k+1) -> ... ->( ..., n) 翻译成伪代码就是：
```
reversekgroup(l, k) {
	for(i = 第 1组到 m组) {
		reverse(第i组)
	}
	
	return res
}
```

## 输出目录
```
├── bin		// 主程序
│   └── chukexin-cpp
├── include
└── test	// 单测
│    └── chukexin-cpp_test
```