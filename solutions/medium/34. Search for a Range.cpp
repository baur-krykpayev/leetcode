/* 
 * Problem: 34. Search for a Range[medium]
 * Source : https://leetcode.com/problems/search-for-a-range/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
 */
 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    { 
        vector<int> ret(2, -1);
        if (!nums.size()) {return ret;}
        
        int left = binSearch(nums, target);
        if (nums[left] != target)
        {
            return ret;
        }
        else
        {
            ret[0] = left;
        }
        
        int right  = binSearch(nums, target+1);
        ret[1] = (nums[right] == target) ? right : right-1;        
        return ret;
    }
private:
    int binSearch(vector<int>& nums, int target)
    {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while (l<r)
        {
            mid = l + (r-l)/2;
            cout << mid << endl;
            if (nums[mid] < target )
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }                 
        }
       
        return l;
    }  
};