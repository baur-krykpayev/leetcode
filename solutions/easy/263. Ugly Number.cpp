/* 
 * Problem: 263. Ugly Number [easy]
 * Source : https://leetcode.com/problems/ugly-number/description/
 * Solver : Baur Krykpayev
 * Date   : 07/29/2018
 */

bool isUgly(int num) 
{   
    if (!num) {return false;}   
 
    while (!(num%2))
    {
        num >>= 1;
    }
 
    while (!(num%3))
    {
        num /=3;
    }
    
    while (!(num%5))
    {
        num /=5;
    }

    return (num == 1);
}