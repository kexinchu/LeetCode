/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
    /**
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique
    */
public:
    // 如果整体的gas比cost大，则必然有一个starting point； 反之则没有
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int roadDis = gas.size();
        int totalGas = 0, totalCost = 0;
        int startingPos = 0, curGas = 0;
        for (int pos = 0; pos < roadDis; pos++) {
            totalGas += gas[pos];
            totalCost += cost[pos];
            curGas += (gas[pos] - cost[pos]);

            // if curGas < 0; choose another start point
            if (curGas < 0) {
                startingPos = pos + 1;
                curGas = 0;
            }
        }
        if (totalGas < totalCost) return -1;
        return startingPos;
    }
};
// @lc code=end

