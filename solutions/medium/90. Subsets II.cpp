/* 
 * Problem: 90. Subsets II [medium]
 * Source : https://leetcode.com/problems/subsets-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 01/08/2018
 */
 
class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(temp, 0, nums, ret);
        return ret; 
    }
    
private:
    void helper(vector<int> &temp, int start, vector<int> &nums, vector<vector<int>> &ret)
    {
        ret.push_back(temp);
        
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i-1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            helper(temp, i+1, nums, ret);
            temp.pop_back();
        }
    }
};