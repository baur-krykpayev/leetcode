/* 
 * Problem: 293. Flip Game [easy]
 * Source : https://leetcode.com/problems/flip-game/description/
 * Solver : Baur Krykpayev
 * Date   : 5/19/2018
 */

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) 
    {
        vector<string> ret;

        for (int i = 1; i < s.length(); i++)
        {
            if (s.substr(i-1,2) == "++")
            {
                string temp = s;
                temp[i-1] = '-'; temp[i] = '-'; 
                ret.push_back(temp);
            }
        }
        
        return ret;
        
    }
};