/* 
 * Problem: 46. Permutations[medium]
 * Source : https://leetcode.com/problems/permutations/description/
 * Solver : Baur Krykpayev
 * Date   : 11/24/2017
 */
 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        vector<int> temp;
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
                temp.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                
                helper(temp, nums, ret);
                
                nums.insert(nums.begin() + i, temp[temp.size() - 1]);
                temp.pop_back();
            }
        }
    }
};