/* 
 * Problem: 560. Subarray Sum Equals K[medium]
 * Source : https://leetcode.com/problems/subarray-sum-equals-k/description/
 * Solver : Baur Krykpayev
 * Date   : 11/19/2017
 */
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        int sum = 0;
        unordered_map <int, int> hash;
        hash.insert(make_pair(0,1));

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if (hash.find(sum - k) != hash.end())
            {
                count += hash[sum-k];
            }
            
            if (hash.find(sum) != hash.end())
            {
                    hash[sum]++;
            }
            else
            {
                 hash[sum] = 1;
            }
        }
        return count;
    }
};