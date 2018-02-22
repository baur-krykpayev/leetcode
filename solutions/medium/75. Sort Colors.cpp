/* 
 * Problem: 75. Sort Colors[medium]
 * Source : https://leetcode.com/problems/sort-colors/description/
 * Solver : Baur Krykpayev
 * Date   : 2/21/2018
 */

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int colors[3] = {0, 0, 0};
        for (auto &num : nums)
        {
            colors[num] += 1;
        }

        int pos = 0;
        for (int color = 0; color < 3; color++)
        {
            while (colors[color]--)
            {
                nums[pos++] = color;
            }
        }
    }
};