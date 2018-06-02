/* 
 * Problem: 280. Wiggle Sort [medium]
 * Source : https://leetcode.com/problems/wiggle-sort/description/
 * Solver : Baur Krykpayev
 * Date   : 6/2/2018
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        if (!nums.size()) {return;}
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size()-1; i += 2)
        {
            swap(nums[i], nums[i+1]);
        }
    }
};