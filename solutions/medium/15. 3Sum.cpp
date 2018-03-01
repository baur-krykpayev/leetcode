/* 
 * Problem: 15. 3Sum[medium]
 * Source : https://leetcode.com/problems/3sum/description/
 * Solver : Baur Krykpayev
 * Date   : 3/1/2018
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        if(nums.size() < 3){return ret;}   
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (i>0 && nums[i] == nums[i-1]){continue;}
            
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            
            while (j < k)
            {
                int sum = nums[j] + nums[k];
             
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ret.push_back(temp);
                    
                    j++; k--;
                    while (nums[j] == nums[j-1]){j++;}
                    while (nums[k] == nums[k+1]){k--;}
                }
                else if (sum < target)
                {
                    j++;
                    while (nums[j] == nums[j-1]){j++;}   
                }
                else
                {
                    k--;
                    while (nums[k] == nums[k+1]){k--;}
                }
            }
        }
        
        return ret;
    }
};