/* 
 * Problem: 526. Beautiful Arrangement[medium]
 * Source : https://leetcode.com/problems/beautiful-arrangement/description/
 * Solver : Baur Krykpayev
 * Date   : 11/23/2017
 */
 
class Solution {
public:
    int countArrangement(int N) 
    {   
        vector<int> nums;
        int len = 1;
        int count = 0;
        
        for (int i = 0; i < N; i++ )
        {
            nums.push_back(i+1);
        }
        
        helper(nums, len, count);
     
        return count;
    }
private:
  
    void helper(vector<int> &nums, int &len, int &count)
    { 
        if (!nums.size())
        {
            count++;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]%len == 0 || len%nums[i] == 0 )
                {
                    int temp = nums[i];
                    nums.erase(nums.begin()+i);
                    helper(nums, ++len, count);
                    nums.insert(nums.begin()+i, temp);
                    len--;
                }
            }
        }
    }
};