/* 
 * Problem: 324. Wiggle Sort II [medium]
 * Source : https://leetcode.com/problems/wiggle-sort-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 6/10/2018
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        if (!nums.size()) {return;}
        int n = nums.size();
        
        auto m = next(nums.begin(), n/2);
        nth_element(nums.begin(), m, nums.end());
        int median = *m;
        
        auto index = [n](int ind){return (1+2*ind)%(n|1);};
        int l = 0, i = 0, r = n-1;
        
        while (i <= r)
        {
            if (nums[index(i)] > median)
            {
                swap(nums[index(i++)], nums[index(l++)]);
            }
            else if(nums[index(i)] < median)
            {
                swap(nums[index(i)], nums[index(r--)]);
            }
            else{i++;}
        }
    }
};