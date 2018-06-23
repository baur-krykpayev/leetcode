/* 
 * Problem: 784. Letter Case Permutation [easy]
 * Source : https://leetcode.com/problems/letter-case-permutation/description/
 * Solver : Baur Krykpayev
 * Date   : 06/23/2018
 */
 
class Solution {
public:
    vector<string> letterCasePermutation(string S) 
    {
        vector<string> ret;
        for (char& c : S) {c = tolower(c);}
        helper(0,S,ret);
        return ret;
    }
    
private:
    void helper(int pos, string S, vector<string>& ret)
    {
        if (pos == S.length())
        {
            ret.push_back(S);
            return;
        }
        
        helper(pos+1, S, ret);
        
        if (isalpha(S[pos]))
        {
            S[pos] = toupper(S[pos]);
            helper(pos+1, S, ret);
        }
    }
};