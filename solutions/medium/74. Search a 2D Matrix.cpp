/* 
 * Problem: 74. Search a 2D Matrix[medium]
 * Source : https://leetcode.com/problems/search-a-2d-matrix/description/
 * Solver : Baur Krykpayev
 * Date   : 02/07/2018
 */
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) {return false;}
    
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int low = 0;
        int high = rows - 1;
        
        while (low < high)
        {
            int mid = low + (high-low)/2;
            if (target <= matrix[mid][cols-1]) {high = mid;}
            else {low = mid + 1;}
        }
        
        int left = 0;
        int right = cols-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (matrix[high][mid] == target) {return true;}
            if (matrix[high][mid] < target) {left = mid + 1;}
            else {right = mid - 1;}
        }
        
        return false;
    }
};