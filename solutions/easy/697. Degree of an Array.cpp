/* 
 * Problem: 697. Degree of an Array [easy]
 * Source : https://leetcode.com/problems/degree-of-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 07/18/2018
 */
 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        map<int, int> hash;
        
        for (int num : nums) {hash[num]++;}
        
        int maxf = 0;
        
        for (auto val : hash)
        {
            if (val.second > maxf)
            {
                maxf = val.second;
            }
        }
        
        if (maxf < 2){return maxf;}
        
        vector<int> cand;
        
        for (auto val : hash)
        {
            if (val.second == maxf)
            {
                cand.push_back(val.first);
            }
        }
        
        int minDiff = INT_MAX;
      
        for(int num : cand)
        {
            int start = -1;
            int end = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == num)
                {
                    if (start == -1)
                    {
                        start = i;
                    }
                    else
                    {
                        end = i;    
                    }
                }
            }
            
            minDiff = min(minDiff, end - start + 1);
        }
        
        return minDiff;
    }
};