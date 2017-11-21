/* 
 * Problem: 692. Top K Frequent Words[medium]
 * Source : https://leetcode.com/problems/top-k-frequent-words/description/
 * Solver : Baur Krykpayev
 * Date   : 11/18/2017
 */
 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string, int> hash;
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> heap;
        vector<string> ret;
        
        for (auto word : words)
        {
            if (hash.find(word) == hash.end())
            {
                hash.insert(make_pair(word, 1));
            }
            else
            {
                hash.find(word)->second +=1;
            }
        }
        
        for(auto word : hash)
        {
            heap.push(word);
        }
        
        for (int i = 0; i < k; i++)
        {
            ret.push_back(heap.top().first);
            heap.pop();
        }
        
        return ret;
    }
    
private:
  
    struct compare
    {
        bool operator()(pair<string,int> n1,pair<string,int> n2) 
        {
            if (n1.second < n2.second)
            {
                return true;
            }
            else if (n1.second == n2.second)
            {
                return n1.first > n2.first;
            }
            return false;
        }
    };
};