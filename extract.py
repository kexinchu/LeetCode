# -*- coding:utf-8 -*-
import random
import sys

if __name__ == "__main__":
    """
    入参：
        1, 文件路径
        2, cache mis比例

    set会产出乱序,取乱序后的 len * 0.2 : len 个元素即可
    """
    url_set = set()
    with open(sys.argv[1], "r") as fr:
        for line in fr:
            url_set.add(line.strip())
    probs = float(sys.argv[2])
    thres = round(len(url_set) * probs)
    print("\n".join(list(url_set)[thres:]))
    