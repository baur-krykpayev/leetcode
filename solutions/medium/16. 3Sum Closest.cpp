/* 
 * Problem: 16. 3Sum Closest[medium]
 * Source : https://leetcode.com/problems/3sum-closest/description/
 * Solver : Baur Krykpayev
 * Date   : 3/13/2018
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int m = INT_MAX;
        int m_sum = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (i>0 && nums[i] == nums[i-1]){continue;}
            
            int j = i+1;
            int k = nums.size()-1;
            
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) { return target;}
                
                if (abs(sum - target) < m)
                {
                    m = abs(sum - target);
                    m_sum = sum;
                }
                
                if (sum < target)
                {
                    j++;
                    while(nums[j-1] == nums[j]) {j++;}
                }
                else
                {
                    k--;
                    while(nums[k+1] == nums[k]) {k--;}
                }
            }
        }
        
        return m_sum;
    }
};