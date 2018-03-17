/* 
 * Problem: 378. Kth Smallest Element in a Sorted Matrix[medium]
 * Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 * Solver : Baur Krykpayev
 * Date   : 3/17/2018
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> allElements;
        
        for (int r = 0; r < matrix.size(); r++)
        {
            allElements.insert(allElements.end(), matrix[r].begin(), matrix[r].end());
        }
        
        sort(allElements.begin(), allElements.end());
        
        return allElements[k-1];
    }
};