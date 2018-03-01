/* 
 * Problem: 127. Word Ladder[medium]
 * Source : https://leetcode.com/problems/word-ladder/description/
 * Solver : Baur Krykpayev
 * Date   : 2/28/2018
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_map<string, vector<string>> map;
        wordList.push_back(beginWord);
        
        for (int i = 0; i < wordList.size(); i++)
        {
            vector<string> temp;
            for (int j = 0; j < wordList.size(); j++)
            {
                if (compareWords(wordList[i], wordList[j]) == 1)
                {
                    temp.push_back(wordList[j]);
                }
            }
            
            if (!temp.empty())
            {
                map[wordList[i]] = temp;    
            }
        }

        queue<string> cur;
        queue<string> next;
        cur.push(beginWord);
        int distance = 1;
        
        while (!map.empty() || !cur.empty() || !next.empty())
        {
            string temp = cur.front();
            cur.pop();
            
            if (map.find(temp) == map.end() && cur.empty() && next.empty()) {return 0;}
            
            for(int i = 0; i < map[temp].size(); i++)
            {
                string neighbor = map[temp][i];
                                    
                if (neighbor == endWord){return distance+1;}
                
                if (map.find(neighbor) != map.end())
                {
                    next.push(neighbor);
                }
            }
            
            map.erase(temp);
         
            if (cur.empty())
            {
                distance++;
                cur.swap(next);
            }
        }
        
        return 0;
    }
    
private:
    
    // helper funciton to compare two words
    int compareWords(string a, string b)
    {
        int mismatch = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i]) {mismatch++;}
        }
        return mismatch;
    }
};