/* 
 * Problem: 503. Next Greater Element II [medium]
 * Source : https://leetcode.com/problems/next-greater-element-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 6/1/2018
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        stack<int> s;
        vector<int> ret (nums.size());
        
        for (int i = 2*nums.size()-1; i >= 0; i--)
        {
            int pos = i % nums.size();
            while (!s.empty() && nums[pos] >= nums[s.top()])
            {
                s.pop();
            }
            
            ret[pos] = (s.empty()) ? -1 : nums[s.top()];
            s.push(pos);
        }
        
        return ret;
    }
};