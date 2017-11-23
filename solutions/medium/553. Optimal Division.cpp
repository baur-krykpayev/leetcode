/* 
 * Problem: 553. Optimal Division[medium]
 * Source : https://leetcode.com/problems/optimal-division/description/
 * Solver : Baur Krykpayev
 * Date   : 11/23/2017
 */
 
class Solution {
public:
    string optimalDivision(vector<int>& nums) 
    {
        string ret;
        
        ret += to_string(nums[0]);
        
        if(nums.size() == 1)
        {
            return ret;
        } 
        ret += '/';
        
        if (nums.size() == 2)
        {
            ret += to_string(nums[1]); 
            return ret;
        }
           
        ret += '(';
        
        for (int i = 1; i < nums.size(); i++)
        {
            ret += to_string(nums[i]);
            ret += '/';
        }
    
        ret[ret.length() - 1] = ')';
                   
        return ret;
    }
};