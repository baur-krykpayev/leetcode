/* 
 * Problem: 380. Insert Delete GetRandom O(1)[medium]
 * Source : https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 * Solver : Baur Krykpayev
 * Date   : 2/19/2018
 */

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
        map.clear();
        vec.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        bool ret = false;
        if (!map.count(val))
        {
            vec.push_back(val);
            map[val] = vec.size()-1;
            ret = true;
        }
        return ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        bool ret = false;
        if (map.count(val))
        {
            map[vec.back()] = map[val];
            vec[map[val]] = vec.back();
            vec.pop_back();
            map.erase(val);
            ret = true;
        }
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        return vec[rand() % vec.size()];
    }
private:
    unordered_map<int, int> map;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */