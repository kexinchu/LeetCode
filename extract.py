# -*- coding:utf-8 -*-
import random
import sys

if __name__ == "__main__":
    url_set = set()
    with open(sys.argv[1], "r") as fr:
        for line in fr:
            url_set.add(line.strip())
    probs = float(sys.argv[2])
    thres = round(len(url_set) * probs)
    print("\n".join(list(url_set)[thres:]))
    