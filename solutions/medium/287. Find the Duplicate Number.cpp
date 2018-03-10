/* 
 * Problem: 287. Find the Duplicate Number [medium]
 * Source : https://leetcode.com/problems/find-the-duplicate-number/description/
 * Solver : Baur Krykpayev
 * Date   : 3/10/2018
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> set;
        int ret = 0;
        
        for (int num : nums)
        {
            if (set.find(num) != set.end())
            {
                ret = num;
                break;
            }
            
            set.insert(num);
        }
        
        return ret;
    }
};