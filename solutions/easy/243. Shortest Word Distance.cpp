/* 
 * Problem: 243. Shortest Word Distance [easy]
 * Source : https://leetcode.com/problems/shortest-word-distance/description/
 * Solver : Baur Krykpayev
 * Date   : 06/14/2018
 */
 
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) 
    {
        vector<int> pos1; vector<int> pos2;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1) {pos1.push_back(i);}
            
            if (words[i] == word2) {pos2.push_back(i);}
        }

        int a = 0, b = 0, ans = INT_MAX;
        while (a < pos1.size() && b < pos2.size())
        {
            ans = min(ans, abs(pos1[a]-pos2[b]));
            if (pos1[a] < pos2[b]) {a++;}
            else {b++;}
        }
        
        return ans;
    }
};