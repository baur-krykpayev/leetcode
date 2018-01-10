/* 
 * Problem: 47. Permutations II
 * Source : https://leetcode.com/problems/permutations-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 01/09/2018
 */
 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(temp, nums, ret);
        return ret;
    }
private:
    void helper(vector<int> &temp, vector<int> &nums, vector<vector<int>> &ret)
    {
        if (!nums.size())
        {
            ret.push_back(temp);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (i>0 && nums[i] == nums[i-1]) {continue;}
                temp.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                helper(temp, nums, ret);
                nums.insert(nums.begin() + i, temp[temp.size() - 1]);
                temp.pop_back();
            }
        }
    }
};