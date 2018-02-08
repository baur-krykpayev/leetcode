/* 
 * Problem: 240. Search a 2D Matrix II[medium]
 * Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
 * Solver : Baur Krykpayev
 * Date   : 02/07/2018
 */
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {return false;}
    
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int r = 0; r < rows; r++)
        {
            if (matrix[r][0] <= target && target <= matrix[r][cols-1])
            {
                if (binarySearch(matrix[r], target)) {return true;}
            }
        }
        return false;   
    }
    
    bool binarySearch(vector<int>& arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (arr[mid] == target) {return true;}
            if (arr[mid] < target) {left = mid + 1;}
            else {right = mid - 1;}
        }
        return false;
    }
};