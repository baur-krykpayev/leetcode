/* 
 * Problem: 506. Relative Ranks [easy]
 * Source : https://leetcode.com/problems/relative-ranks/description/
 * Solver : Baur Krykpayev
 * Date   : 5/26/2018
 */

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) 
    {
        vector<string> ret (nums.size());
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0){ret[map[nums[i]]] = "Gold Medal";}
            else if (i == 1){ret[map[nums[i]]] = "Silver Medal";}
            else if (i == 2){ret[map[nums[i]]] = "Bronze Medal";}
            else{ret[map[nums[i]]] = to_string(i+1);}
        }
        
        return ret;
    }
};