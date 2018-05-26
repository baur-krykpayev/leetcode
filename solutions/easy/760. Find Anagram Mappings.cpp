/* 
 * Problem: 760. Find Anagram Mappings [easy]
 * Source : https://leetcode.com/problems/find-anagram-mappings/description/
 * Solver : Baur Krykpayev
 * Date   : 5/26/2018
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) 
    {
        vector<int> ret;
        unordered_map<int, int> map;
        for (int i = 0; i < B.size(); i++){map[B[i]] = i;}
        for (int i = 0; i < A.size(); i++){ret.push_back(map[A[i]]);}
        return ret;
    }
};