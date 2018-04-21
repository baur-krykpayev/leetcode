/* 
 * Problem: 414. Third Maximum Number [easy]
 * Source : https://leetcode.com/problems/third-maximum-number/description/
 * Solver : Baur Krykpayev
 * Date   : 4/21/2018
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        set<int> s;
        for (auto num : nums)
        {
            s.insert(num);
            
            if (s.size() > 3)
            {
                s.erase(s.begin());
            }
        }
        return (s.size() < 3) ? *s.rbegin() : *s.begin();
    }
};