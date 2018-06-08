/* 
 * Problem: 318. Maximum Product of Word Lengths [medium]
 * Source : https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 * Solver : Baur Krykpayev
 * Date   : 6/7/2018
 */

class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        if (!words.size()) {return 0;}
        int ret = 0;
        for (int i = 0; i < words.size()-1; i++)
        {
            for (int j = i+1; j < words.size(); j++)
            {
                if (!share(words[i], words[j]))
                {
                    int temp = words[i].length()*words[j].length();
                    ret = max(ret, temp);
                }
            }
        }
        
        return ret;
    }
    
private:
    bool share(string a, string b)
    {
        for (char c : a)
        {
            if(b.find(c) != -1)
            {
                return true;
            }
        }
        
        return false;
    }
};