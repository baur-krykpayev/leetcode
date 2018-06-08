/* 
 * Problem: 4. Median of Two Sorted Arrays [hard]
 * Source : https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 * Solver : Baur Krykpayev
 * Date   : 6/6/2018
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        priority_queue<int, vector<int>> higher;
        priority_queue<int, vector<int>, greater<int>> lower;
        
        for (int n : nums1){lower.push(n);}
        for (int n : nums2){lower.push(n);}
        
        while(lower.size()-1 > higher.size())
        {
            higher.push(lower.top());
            lower.pop();
        }
            
        return (lower.size() > higher.size()) ? lower.top() : (lower.top() + higher.top())/2.0;
    }
};