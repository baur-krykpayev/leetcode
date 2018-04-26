/* 
 * Problem: 342. Power of Four [easy]
 * Source : https://leetcode.com/problems/power-of-four/description/
 * Solver : Baur Krykpayev
 * Date   : 4/26/2018
 */

class Solution {
public:
    bool isPowerOfFour(int num) 
    {
        return (num>0) && !((num-1)&num) && !((num-1)%3);
    }
};