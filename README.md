# LeetCode刷题学习

## 剑指Offer
### 栈与队列
- [x] [09，用两个栈实现队列](https://github.com/kexinchu/LeetCode/blob/master/sword-to-offer/Sword-09.stack&queue.CQueue.cpp)
- [x] 30，包含min函数的栈  
- [x] 59-I，滑动窗口的最大值  
- [x] 59-II，队列的最大值  
- [x] 《队列，双向队列，单调队列，优先队列》

### 链表
- [x] 06，从尾到头打印链表  
- [x] 24，反转链表  
- [x] 35，复杂链表的复制  

### 字符串
- [x] 05，替换空格  <字符数组>
- [x] 58-I. 翻转单词顺序  
- [x] 58-II，左旋转字符串
- [x] 20，表示数值的字符串 <有限状态机>
- [x] 67，把字符串转换成正数

### 查找算法
- [x] 03，数组中重复的数字
- [x] 53-I，在排序数组中查找数字
- [x] 53-II，0 ~ n-1中缺失的数字
- [x] 04，二维数组中的查找
- [x] 11，旋转数组的最小数字
- [x] 50，第一个只出现一次的字符

### 搜索与回溯算法
- [x] 32-I，32-II，32-III，从上到下打印二叉树
- [x] 26，树的子结构
- [x] 27，二叉树的镜像
- [x] 28，对称二叉树
- [x] 34，二叉树中和为某一值的路径
- [x] 36，二叉搜索树与双向链表
- [x] 54，二叉搜索树的第k大节点
- [x] 55-I, 二叉树的深度
- [x] 55-II, 平衡二叉树
- [x] 64，求1+2+3+… +n
- [x] 68-I  二叉搜索数的最近祖先
- [x] 68-II 二叉树的最近公共祖先
- [x] 37，序列化二叉树
- [x] 38，字符串的排列
   - [ ] [C++ String](https://cplusplus.com/reference/string/string/?kw=string)
      - push_back()
      - pop_back()

### 分治算法
- [x] 07，重建二叉树
- [x] 16，数值的整数次方
- [x] 33，二叉搜索树的后序遍历
- [x] 17，打印从1到最大的n个数
- [ ] 51，数组中的逆序对

### 动态规划
- [x] 10，斐波那契数列 + 跳台阶
- [x] 63，股票的最大利润
- [x] 42，连续子树组的最大和
- [x] 47，礼物的最大价值
- [x] 46，把数字翻译成字符串
- [x] 48，最长不含重复字符的子串
- [x] 19，正则表达式匹配
   <img src="https://github.com/kexinchu/LeetCode/blob/master/sword-to-offer/pictures/dynamic-19.jpg" width="350px">
   - 从后向前递归处理会遇到下面这个问题： "aaa"  => "ab*a*c*a" 是true； 但从后往前递归是false, 因为*a会遍历完全部"aaa"
   - 说明: 动态规划，尝试使用二维数据解决
      - case1，p 的char 'a - z': 1比1的匹配
         if p[i] = s[j] : f[i][j] = f[i-1][j-1]
         else : false
      - case2，p 的char '.': 指代任意一个字符
         f[i][j] = f[i-1][j-1]
      - case3，p 的char '*': 需要和'*'前的字符匹配, 可以出现任意多次
         匹配0次 f[i][j] = f[i-2][j]
         匹配1次 f[i][j] = f[i-2][j-1]
         匹配2次 f[i][j] = f[i-2][j-2]
         匹配3次 f[i][j] = f[i-2][j-3]
         ... ...
         总结 => 两种情况
            if p[i-1] != s[j] :  // 0次
               f[i][j] = f[i-2][j]
            else :               // 0次或者1次
               if p[i-1] == s[j]: f[i][j] = f[i][j-1] || f[i-2][j]
      ```
      状态定义:  设动态规划矩阵 dp, dp[i][j] 代表字符串 s 的前 i 个字符和 p 的前 j 个字符能否匹配

      转移方程:  需要注意, 由于 dp[0][0] 代表的是空字符的状态,  因此 dp[i][j] 对应的添加字符是 s[i-1] 和 p[j-1]
      当 p[j - 1] = '*' 时:
         注意: 所以 s[i-1] == p[j-2] || '.' == p[j-2] 时不一定至少出现1次, 也可能不出现; eg: "a" 和 "ab*a*"
         if s[i - 1] == p[j - 2] || '.' == p[j-2] 时, '_*'有可能出现1次或更多次
               dp[i][j] = dp[i-1][j] || dp[i][j-2]
         if s[i - 1] != p[j - 2] && '.' != p[j-2] 时, '_*'必然只出现0次
               dp[i][j] = dp[i][j-2]
      当 p[j - 1] != '*' 时:
         if s[i - 1] == p[j - 2] || '.' == p[j-2] 
               dp[i][j] = dp[i-1][j-1]

      初始化:  需要先初始化 dp 矩阵首行, 以避免状态转移时索引越界
         dp[0][0] = true:        代表两个空字符串能够匹配
         dp[0][j] = dp[0][j - 2] 且 p[j - 1] = '*':  首行 s 为空字符串, 因此当 p 的偶数位为时才能够匹配
                                                     (即让 p 的奇数位出现 0 次, 保持 p 是空字符串); 
                                                     因此, 循环遍历字符串 p , 步长为 2（即只看偶数位）

      返回值:  dp 矩阵右下角字符, 代表字符串 s 和 p 能否匹配
      ```
- [ ] 49，丑数
- [ ] 60，n个骰子的点数

### 双指针
- [x] 18，删除链表的节点
- [x] 22，链表中倒数第k个节点
- [x] 25，合并两个排序的节点
- [x] 52，两个链表的第一个公共节点
- [x] 21，调整数组顺序是奇数位于偶数前面
- [x] 57-I，和为s的两个数字
- [x] 58，翻转单词顺序

### 排序
- [x] 45，把数组排成最小的数
- [x] 61，扑克牌中的顺子
- [x] 40，最小的k个数
- [x] 41，数据流中的中位数

### 位运算
- [x] 15，二进制中1的个数
- [x] 65，不用加减乘除做加法
- [x] 56-I, 数组中数字出现的次数
- [x] 56-II,  数组中数字出现的次数 II

### 数学
- [x] 39，数组中出现次数超过一半的数字
- [x] 66，构建乘积数组
- [x] 14，14-II，剪绳子
- [x] 57-II，和为s的连续正数序列
- [x] 62，圆圈中最后剩下的数字
- [ ] 43，1 ~ n 整数中1出现的次数
- [ ] 44，数字序列中某一位的数字

### 模拟
- [ ] 29，顺时针打印矩阵
- [ ] 31，栈的压入、弹出序列

## 百度C++ GoodCoder考试
- 选择 **固定题目二**【用C/C++实现】K 个一组翻转链表
- [代码](https://github.com/kexinchu/LeetCode/tree/master/reverse-k-group-link-list)


## Leetcode 刷题
- [ ] 4, find median sorted arrays
- [ ] 5, longest palindromic substring
- [ ] 10, regular expression match
- [ ] 32, longest valid parentheses
- [ ] 50, pow-x-n
- [ ] 74, search-2D-matrix
- [ ] 240, search-2D-matrix-ii
- [ ] 297, serialize-and-deserialize-binary-tree
- [ ] 395, longest-substring-with-at-least-K-repeating-characters
- [ ] 397, integer-replacement
- [ ] 449, serialize-and-deserialize-BST
- [ ] 453, Minimun-Moves-to-Equal-Array-Elements
- [ ] 563, Binary-Tree-Tilt
- [ ] 1732, largest-altitude
