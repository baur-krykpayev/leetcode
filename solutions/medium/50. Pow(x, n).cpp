/* 
 * Problem: 50. Pow(x, n)[medium]
 * Source : https://leetcode.com/problems/powx-n/description/
 * Solver : Baur Krykpayev
 * Date   : 02/04/2018
 */
 
class Solution {
public:
    double myPow(double x, int n) 
    {
        long long N = n;
        double res = 1;
        if ( n < 0) {x = 1/x; N = -N;}
        
        while(N) 
        {
            if (N & 1) {res *= x;}    
            x *= x;
            N >>= 1;
        }
    
        return res;
    }
};