/* 
 * Problem: 739. Daily Temperatures[medium]
 * Source : https://leetcode.com/problems/daily-temperatures/description/
 * Solver : Baur Krykpayev
 * Date   : 02/13/2018
 */
 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int> s;
        vector<int> ret (temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && (temperatures[s.top()] < temperatures[i]))
            {
                int ind = s.top();
                s.pop();
                ret[ind] = i-ind;
            }
            s.push(i);
        }
        return ret;
    }
};