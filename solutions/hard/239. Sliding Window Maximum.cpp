/* 
 * Problem: 239. Sliding Window Maximum [hard]
 * Source : https://leetcode.com/problems/sliding-window-maximum/description/
 * Solver : Baur Krykpayev
 * Date   : 4/20/2018
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int> d;
        vector<int> ret;
        if (!nums.size()) {return ret;}
        
        for (int i = 0; i < nums.size(); i++)
        {
            // maintain the deque size of k
            if (!d.empty() && d.front() == i-k)
            {
                d.pop_front();
            }
            
            // maintain monotonic decreasing sequence
            while(!d.empty() && nums[i] > nums[d.back()])
            {
                d.pop_back();
            }
            
            d.push_back(i);
            
            if (i >= k-1)
            {
                ret.push_back(nums[d.front()]);
            }
        }
        
        return ret;
    }
};