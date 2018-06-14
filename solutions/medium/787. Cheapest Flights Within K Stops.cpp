/* 
 * Problem: 787. Cheapest Flights Within K Stops [medium]
 * Source : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 * Solver : Baur Krykpayev
 * Date   : 06/13/2018
 */
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto flight : flights)
        {
            graph[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
    
        priority_queue<pair<int, pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<>> to_visit;
        to_visit.push(make_pair(0,make_pair(src, K+1)));
        
        while (!to_visit.empty())
        {
            pair<int,pair<int,int>> vertex = to_visit.top();
            to_visit.pop();
            int cost = vertex.first;
            int city = vertex.second.first;
            int stop = vertex.second.second;
            if (city == dst) {return cost;}
            if (!stop) {continue;}
            
            for (auto edge : graph[city])
            {
                int next = edge.first;
                int ticket = edge.second;
                to_visit.push(make_pair(cost + ticket, make_pair(next, stop-1))); 
            }
        }
        
        return -1;
    }
};