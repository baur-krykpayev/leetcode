/* 
 * Problem: 645. Set Mismatch [easy]
 * Source : https://leetcode.com/problems/set-mismatch/description/
 * Solver : Baur Krykpayev
 * Date   : 4/21/2018
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int a = -1, b = -1;
        
        for (auto num : nums)
        {
            if(nums[abs(num) - 1] < 0)
            {
                a = abs(num);    
            }
            else
            {
                nums[abs(num) - 1] *= -1;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                b = i+1;
            }    
        }
        
        return {a, b};
    }
};