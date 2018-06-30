/* 
 * Problem: 852. Peak Index in a Mountain Array [easy]
 * Source : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 * Solver : Baur Krykpayev
 * Date   : 06/29/2018
 */
 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int l = 0;
        int r = A.size()-1;
        
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (A[mid-1] < A[mid] && A[mid] > A[mid+1])
            {
                return mid;
            }
            else if (A[mid-1] < A[mid])
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        
        return -1;
    }
};