/* 
 * Problem: 565. Array Nesting [medium]
 * Source : https://leetcode.com/problems/array-nesting/description/
 * Solver : Baur Krykpayev
 * Date   : 07/21/2018
 */
 
class Solution {
public:
    int arrayNesting(vector<int>& nums) 
    {
        vector<bool> visited (nums.size(), false);
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int j = i;
            int temp = 0;
            
            while (!visited[j])
            {
                visited[j] = true;
                temp++;
                j = nums[j];
            }
        
            ans = max(ans, temp);
        }
        
        return ans;
    }
};