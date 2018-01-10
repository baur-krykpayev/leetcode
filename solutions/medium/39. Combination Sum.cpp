/* 
 * Problem: 39. Combination Sum [medium]
 * Source : https://leetcode.com/problems/combination-sum/description/
 * Solver : Baur Krykpayev
 * Date   : 01/09/2018
 */
 
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(0, 0, temp, target, candidates, ret);
        return ret;
    }
    
private:
    void helper(int start, int sum, vector<int> &temp, int target, vector<int>& candidates, vector<vector<int>> &ret)
    {
        if (sum == target)
        {
            ret.push_back(temp);
            return;    
        }
        else if (sum > target)
        {
            return;
        }
    
        for (int i = start; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            sum += candidates[i];
            helper(i, sum, temp, target, candidates, ret);
            sum -= candidates[i];
            temp.pop_back();
        }
    }
};