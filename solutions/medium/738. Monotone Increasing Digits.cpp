/* 
 * Problem: 738. Monotone Increasing Digits [medium]
 * Source : https://leetcode.com/problems/monotone-increasing-digits/description/
 * Solver : Baur Krykpayev
 * Date   : 4/24/2018
 */

class Solution {
public:
    int monotoneIncreasingDigits(int N) 
    {
        int res = 0;
        if (!N) {return res;}
        vector<int> num;
        int ind = INT_MIN;
        
        while (N)
        {
            num.push_back(N%10);
            N /= 10;
        }
        
        for (int i = 1; i < num.size(); i++)
        {
            if(num[i] > num[i-1])
            {
                ind = i-1;
                num[i]--;
            }
        }
        
        for (int i = 0; i < num.size(); i++)
        {
            if (i<= ind){num[i] = 9;}
        }
        
        for (int i = 0; i < num.size(); i++)
        {
            res += num[i] * pow(10, i);    
        }
        
        return res;
    }
};