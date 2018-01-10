/* 
 * Problem: 40. Combination Sum II[medium]
 * Source : https://leetcode.com/problems/combination-sum-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 01/09/2018
 */
 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i-1]) {continue;}
            temp.push_back(candidates[i]);
            sum += candidates[i];
            helper(i+1, sum, temp, target, candidates, ret);
            sum -= candidates[i];
            temp.pop_back();
        }
    }
};