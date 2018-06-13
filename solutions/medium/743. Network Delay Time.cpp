/* 
 * Problem: 743. Network Delay Time [medium]
 * Source : https://leetcode.com/problems/network-delay-time/description/
 * Solver : Baur Krykpayev
 * Date   : 06/12/2018
 */
 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        unordered_map<int, vector<pair<int,int>>> graph;
        
        for (auto time : times)
        {
            graph[time[0]].push_back(make_pair(time[1],time[2]));    
        }
        
        unordered_map<int, int> dist;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> to_visit;
        to_visit.push(make_pair(0,K));
        
        while (!to_visit.empty())
        {
            pair<int, int> node = to_visit.top();
            to_visit.pop(); 
            int d = node.first;
            int src = node.second;
            if (dist.find(src) != dist.end()){continue;}
            dist[src] = d;
            
            for (auto edge : graph[src])
            { 
                int dst = edge.first;
                int w = edge.second;
                if (dist.find(dst) == dist.end())
                {
                    to_visit.push(make_pair(d+w, dst));
                }
            }
        }
        
        int cnt = 0;
        for (auto d : dist)
        {
            cnt = max(cnt, d.second);
        }
        
        return (dist.size() == N) ? cnt : -1;
    }
};