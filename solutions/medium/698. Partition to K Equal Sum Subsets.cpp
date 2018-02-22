/* 
 * Problem: 698. Partition to K Equal Sum Subsets [medium]
 * Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 * Solver : Baur Krykpayev
 * Date   : 2/21/2018
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        if (k == 1) {return true;}
        int sum = 0;
        vector<bool> visited (nums.size(), false);
        for (auto num : nums) {sum += num;}
        if (k<=0 || sum%k != 0) {return false;}
        sort(nums.begin(), nums.end(), [](auto &left, auto &right){ return left > right;});
        return dfs(0, 0, visited, nums, sum/k, k);
    }
    
    bool dfs(int bucket, int pos, vector<bool>& visited, vector<int>& nums, int partition, int k)
    {                
        if (k == 1){return true;}
        if (bucket == partition) {return dfs(0, 0, visited, nums, partition, k-1);}
        
        for (int i = pos; i < nums.size(); i++)
        {
            if (!visited[i] && (bucket + nums[i] <= partition))
            {
                visited[i] = true;
                if (dfs(bucket + nums[i], i+1, visited, nums, partition, k))
                {
                    return true;
                }
                visited[i] = false;
            }
        }
                
        return false;
    }
};