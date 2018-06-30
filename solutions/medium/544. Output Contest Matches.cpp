/* 
 * Problem: 544. Output Contest Matches [medium]
 * Source : https://leetcode.com/problems/output-contest-matches/description/
 * Solver : Baur Krykpayev
 * Date   : 06/30/2018
 */
 
class Solution {
public:
    string findContestMatch(int n) 
    {
        vector<string> str;
        for (int i = 1; i <= n; i++)
        {
            str.push_back(to_string(i));
        }
        
        return helper(str);
    }
    
private:   
    string helper(vector<string> str)
    {
        if(str.size() == 1)
        {
            return str[0];
        }

        vector<string> temp;
        int l = 0;
        int r = str.size()-1;
        
        while (l<r)
        {
            temp.push_back("(" + str[l] + "," + str[r] + ")" );
            l++; r--;
        }
        
        return helper(temp);
    }
};