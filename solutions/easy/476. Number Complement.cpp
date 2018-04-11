/* 
 * Problem: 476. Number Complement [easy]
 * Source : https://leetcode.com/problems/number-complement/description/
 * Solver : Baur Krykpayev
 * Date   : 4/10/2018
 */

class Solution {
public:
    int findComplement(int num) 
    {
        for (long i = 1; i <= num; i = i*2)
        {
            num = num^i;   
        }
        
        return num;
    }
};