/* 
 * Problem: 210. Course Schedule II [medium]
 * Source : https://leetcode.com/problems/course-schedule-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 3/7/2018
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<int> ret;
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false);
        vector<bool> gray(numCourses, false);
        stack<int> path;
        
        for (int course = 0; course < numCourses; course++)
        {
            if (!visited[course] && topSort(graph, course, path, gray, visited))
            {
                break;
            }
        }
        
        if (path.size() == numCourses)
        {
            while(!path.empty())
            {
                ret.push_back(path.top());
                path.pop();
            }
        }
        
        return ret;
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
    
    bool topSort(vector<unordered_set<int>>& graph, int course, stack<int>& path, vector<bool>& gray, vector<bool>& visited)
    {
        if (visited[course]) {return false;}
        visited[course] = true;
        gray[course] = true;
        
        for (int req : graph[course])
        {
            if (gray[req] || topSort(graph, req, path, gray, visited))
            {
                return true;
            }
        }
        
        path.push(course);
        gray[course] = false;
        
        return false;
    }
};