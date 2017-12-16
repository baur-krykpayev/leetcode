/* 
 * Problem: 31. Next Permutation[medium]
 * Source : https://leetcode.com/problems/next-permutation/description/
 * Solver : Baur Krykpayev
 * Date   : 12/16/2017
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int dip = nums.size()-2;
        
        while (dip>=0)
        {
            if (nums[dip+1] > nums[dip])
            {
                break;
            }
            dip--;
        }
        
        if (dip >= 0) 
        {
            int temp = nums.size() - 1;
            
            while (dip < temp)
            {
                if (nums[dip] < nums[temp])
                {
                    break;
                }
                
                temp--;
            }
            swap(nums[dip], nums[temp]);
        }

        reverse(nums.begin()+dip+1, nums.end());
    }
};