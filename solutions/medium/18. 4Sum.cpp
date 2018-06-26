/* 
 * Problem: 18. 4Sum [medium]
 * Source : https://leetcode.com/problems/4sum/description/
 * Solver : Baur Krykpayev
 * Date   : 06/25/2018
 */
 
class Solution {
public:    
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int,int>>> hash;
        unordered_set<vector<int>, VectorHash> temp_ans;
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                
                for (auto pair : hash[sum])
                {
                    vector<int> temp = {pair.first, pair.second, nums[i], nums[j]};
                    temp_ans.insert(temp);
                }
            }
            
            for (int k = 0; k < i; k++)
            {
                int comp = target - (nums[k] + nums[i]); 
                hash[comp].push_back(make_pair(nums[k], nums[i]));
            }
        }
        
        for (auto vec : temp_ans)
        {
            ans.push_back(vec);
        }
        
        return ans;
    }
    
private:
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const 
    {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }};
};