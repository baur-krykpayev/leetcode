/* 
 * Problem: 599. Minimum Index Sum of Two Lists [easy]
 * Source : https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 * Solver : Baur Krykpayev
 * Date   : 07/11/2018
 */
 
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> hash;
        vector<string> ans;
        for(int i = 0; i < list1.size(); i++){hash[list1[i]] = i;}
        
        int min_sum = INT_MAX;
        
        for(int i = 0; i < list2.size(); i++)
        {
            string temp = list2[i];
            if(hash.find(temp) != hash.end())
            {
                int temp_sum = i + hash[temp];
                if (temp_sum < min_sum)
                {
                    min_sum = temp_sum;
                }
            }
        }
        
        for(int i = 0; i < list2.size(); i++)
        {
            string temp = list2[i];
            if(hash.find(temp) != hash.end())
            {
                int temp_sum = i + hash[temp];
                if (temp_sum == min_sum)
                {
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};