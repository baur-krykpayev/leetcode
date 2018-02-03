/* 
 * Problem: 80. Remove Duplicates from Sorted Array II[medium]
 * Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 02/03/2018
 */
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() < 3)
        {
            return nums.size();
        }
        
        vector<int> nodup (nums[nums.size()-1] - nums[0] + 1, 0);
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int shift = nums[i]-nums[0];
            if (nodup[shift] < 2)
            {
                nodup[shift]++;
            }
        }
        
        for (int i = 0; i < nodup.size(); i++)
        {
            while (nodup[i])
            {
                nums[count] = i + nums[0];
                count++;
                nodup[i]--;
            }
        }
        
        return count;
    }
};