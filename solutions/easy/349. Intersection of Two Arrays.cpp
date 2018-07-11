/* 
 * Problem: 349. Intersection of Two Arrays [easy]
 * Source : https://leetcode.com/problems/intersection-of-two-arrays/description/
 * Solver : Baur Krykpayev
 * Date   : 07/10/2018
 */
 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s;
        unordered_set<int> ans_s;
        
        for (auto n : nums1) {s.insert(n);}
        
        for (auto n : nums2) 
        {
            if (s.count(n))
            {
                ans_s.insert(n);
            }
        }
        vector<int> ans(ans_s.begin(), ans_s.end());
        
        return ans;
    }
};