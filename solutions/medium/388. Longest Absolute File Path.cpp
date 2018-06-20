/* 
 * Problem: 388. Longest Absolute File Path [medium]
 * Source : https://leetcode.com/problems/longest-absolute-file-path/description/
 * Solver : Baur Krykpayev
 * Date   : 06/19/2018
 */
 
class Solution {
public:
    int lengthLongestPath(string input) 
    {
        unordered_map<int,int> levels;
        levels[0] = 0;
        int len = 0, lvl = 0, ret = 0;
        bool file = false;
        int i = 0;
        while (i < input.length())
        {
            while(input[i] == '\t')
            {
                lvl++; i++;
            }
            
            while (i < input.length() && input[i] != '\n' )
            {
                if (input[i] == '.') { file = true;}
                len++; i++;
            }

            if(file)
            {
                ret = max(ret,  levels[lvl-1] + len);
            }
            else
            {
                levels[lvl] = levels[lvl-1] + len + 1;
            }
            
            len = 0, lvl = 0; file = false;
            i++;
        }
        
        return ret; 
    }
};