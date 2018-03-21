/* 
 * Problem: 763. Partition Labels [medium]
 * Source : https://leetcode.com/problems/partition-labels/description/
 * Solver : Baur Krykpayev
 * Date   : 3/20/2018
 */

class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        vector<int> ret;
        vector<int> map (26, -1);
        
        for (int i = 0; i < S.length(); i++)
        {
            map[S[i] - 'a'] = i;
        }
        
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < S.length(); i++)
        {
            if (i != map[S[i] - 'a'])
            {
                end = max(end, map[S[i] - 'a']);
            }
            else
            {
                if (i == end)
                {
                    ret.push_back(end-start+1);
                    start = i+1;
                    end = start;
                }
            }
        }
        
        return ret;
    }
};