/* 
 * Problem: 357. Count Numbers with Unique Digits[medium]
 * Source : https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 * Solver : Baur Krykpayev
 * Date   : 11/24/2017
 */
 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        vector<int> nums;
        int count = 0;
        string str;
        int zeroes = 0;
        
        for (int i = 0; i < 10; i++)
        {
            nums.push_back(i);
        }
        
        helper(n, nums, str, count, zeroes);
        return count;
    }
    
    void helper(int n, vector<int> &nums, string &str, int &count, int &zeroes)
    {
        if (!n)
        {
            count++;
        } 
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                int temp =  nums[i];
                zeroes += temp;
                
                if (zeroes)
                {
                    nums.erase(nums.begin() + i);    
                }
                
                helper(n-1, nums, str, count, zeroes);
                
                if (zeroes)
                {
                    nums.insert(nums.begin() + i, temp);    
                }
                zeroes -= temp;
            }
        }
    }
};