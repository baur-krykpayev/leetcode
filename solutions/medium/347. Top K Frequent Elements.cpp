/* 
 * Problem: 347. Top K Frequent Elements [medium]
 * Source : https://leetcode.com/problems/top-k-frequent-elements/description/
 * Solver : Baur Krykpayev
 * Date   : 2/19/2018
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ret;
        unordered_map<int, int> map;
        priority_queue<pair<int,int>> max_heap;
        
        for (auto& num : nums)
        {
            map[num]++;         
        }
        
        for (auto it = map.begin(); it != map.end(); it++)
        {
            max_heap.push(make_pair(it->second, it->first));   
        }
        
        for (int i = 0; i < k; i++)
        {
            ret.push_back(max_heap.top().second);
            max_heap.pop();
        }
    
        return ret;
    }
};