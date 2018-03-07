/* 
 * Problem: 207. Course Schedule [medium]
 * Source : https://leetcode.com/problems/course-schedule/description/
 * Solver : Baur Krykpayev
 * Date   : 3/7/2018
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> gray(numCourses, false);
        for (int course = 0; course < numCourses; course++)
        {
            if (!visited[course] && hasCycle(graph, course, gray, visited))
            {
                return false;
            }
        }
        
        return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> ret(numCourses);
        
        for (auto req : prerequisites)
        {
           ret[req.second].insert(req.first);
        }
        
        return ret;
    }
    
    bool hasCycle(vector<unordered_set<int>>& graph, int course,  vector<bool>& gray, vector<bool>& visited)
    {
        if (visited[course]) {return false;}
        visited[course] = true;
        gray[course] = true;
        
        for (int req : graph[course])
        {
            if (gray[req] || hasCycle(graph, req, gray, visited))
            {
                return true;
            }
        }
        
        gray[course] = false;
        
        return false;
    }
    
    
};