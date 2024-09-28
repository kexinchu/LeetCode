/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
/**
Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. 
        Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. 
        Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements 
        (it's guaranteed that at least one element exists when this method is called). 
        Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet {
private:
    unordered_map<int, int> rsMap;  // val - index
    vector<int> rsList;
public:
    RandomizedSet() {
        // initial a RandomizedSet
    }
    
    bool insert(int val) {
        // already exist
        if (!rsMap.empty() && rsMap.find(val) != rsMap.end()) {
            return false;
        }
        // insert
        rsMap[val] = rsList.size();
        rsList.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // not exist
        if (rsMap.empty()|| rsMap.find(val) == rsMap.end()) {
            return false;
        }
        // change the val to final
        int index = rsMap[val];
        int tmp = rsList.back();
        rsList[index] = tmp;
        rsList.pop_back();
        rsMap[tmp] = index;

        // delete
        rsMap.erase(val);
        return true;
    }
    
    int getRandom() {
        // random index
        int randomIdx = std::rand() % rsList.size();
        return rsList[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

