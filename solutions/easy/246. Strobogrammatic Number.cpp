/* 
 * Problem: 246. Strobogrammatic Number [easy]
 * Source : https://leetcode.com/problems/strobogrammatic-number/description/
 * Solver : Baur Krykpayev
 * Date   : 5/16/2018
 */

class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        int left = 0;
        int right = num.length()-1;
        
        while(left<=right)
        {
            int l = num[left] - '0';
            int r = num[right] - '0';
            
            if (l != r)
            {
                if ((l==6 && r==9) || (l==9 && r==6)){}
                else {return false;}
            }
            else
            {
                if (l == 1 || l == 8 || l == 0){}
                else {return false;} 
            }
            
            left++;
            right--;
        }
            
        return true;
    }
};