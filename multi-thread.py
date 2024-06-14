#!/usr/bin/python3

import _thread
import os

# 为线程定义一个函数
def run_xdns(threadName, count):
    os.system("bash run-uniform-filter2k-xdns.sh " + str(count))

# 创建两个线程
for count in range(10):
   _thread.start_new_thread(run_xdns, ("Thread_" + str(count), count))