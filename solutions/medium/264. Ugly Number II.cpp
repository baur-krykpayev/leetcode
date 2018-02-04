/* 
 * Problem: 264. Ugly Number II[medium]
 * Source : https://leetcode.com/problems/ugly-number-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 02/04/2018
 */
 
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        if (n <= 0) {return 0;}
        if (n == 1) {return 1;}
        
        vector<int> ugly (1,1);
        int i = 0; int j = 0; int k = 0;
                
        while (--n)
        {
            ugly.push_back(min(ugly[i]*2, min(ugly[j]*3, ugly[k]*5)));
            if (ugly[i]*2 == ugly.back()) {i++;}
            if (ugly[j]*3 == ugly.back()) {j++;}
            if (ugly[k]*5 == ugly.back()) {k++;}
        }
        
        return ugly.back();
    }
};