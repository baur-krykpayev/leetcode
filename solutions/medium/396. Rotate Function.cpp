/* 
 * Problem: 396. Rotate Function [medium]
 * Source : https://leetcode.com/problems/rotate-function/description/
 * Solver : Baur Krykpayev
 * Date   : 4/25/2018
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& A) 
    {
        if (!A.size()){return 0;}
        long long fun = 0;
        long long sum = 0;
        long long ret = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            fun += A[i] * i;
            sum += A[i];
        }
        
        ret = fun;
        
        for (int i = 0; i < A.size(); i++)
        {
            fun += (A[i]*A.size() - sum);
            ret = max(ret, fun);
        }
        
        return ret;
    }
};