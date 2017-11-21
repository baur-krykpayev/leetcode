/* 
 * Problem: 477. Total Hamming Distance[medium]
 * Source : https://leetcode.com/problems/total-hamming-distance/description/
 * Solver : Baur Krykpayev
 * Date   : 11/20/2017
 */
 
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) 
    { 
        if(!nums.size()){return 0;}
        
        int count  = 0;
        int maxNum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxNum < nums[i])
            {
                maxNum = nums[i];
            }
        }   
        
        while (maxNum)
        {
            int zeroes = 0;
            int ones = 0;
            
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]%2) 
                {
                    ones++;
                }
                else
                {
                    zeroes++;
                }
                nums[i]>>=1;
            }  
            count += zeroes*ones;
            maxNum>>=1;
        }        
        return count;
    }
};