/* 
 * Problem: 77. Combinations [medium]
 * Source : https://leetcode.com/problems/combinations/description/
 * Solver : Baur Krykpayev
 * Date   : 01/08/2018
 */
 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(temp, 1, n, k, ret);
        return ret; 
    }
    
private:
    void helper(vector<int> &temp, int start, int n, int k, vector<vector<int>> &ret)
    {
        if (!k){ret.push_back(temp);}
        
        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            helper(temp, i+1, n, k-1, ret);
            temp.pop_back();
        }
    }
};