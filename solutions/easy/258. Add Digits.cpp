/* 
 * Problem: 258. Add Digits [easy]
 * Source : https://leetcode.com/problems/add-digits/description/
 * Solver : Baur Krykpayev
 * Date   : 06/27/2018
 */
 
class Solution {
public:
    int addDigits(int num) 
    {
        return (num%9 || !num) ? num%9 : 9;
    }
};