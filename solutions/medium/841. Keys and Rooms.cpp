/* 
 * Problem: 841. Keys and Rooms [medium]
 * Source : https://leetcode.com/problems/keys-and-rooms/description/
 * Solver : Baur Krykpayev
 * Date   : 6/2/2018
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {   
        unordered_set<int> s;
        vector<bool> visited(rooms.size(), false);
     
        for (int room = 0; room < rooms.size(); room++)
        {
            if (!visited[room])
            {
                if (room == 0 || s.count(room))
                {
                    dfs(room, visited, s, rooms);
                }
                else
                {
                    return false;   
                }
            }
        }
     
        return true;   
    }
    
private:
    void dfs(int room, vector<bool>& visited, unordered_set<int>& s,  vector<vector<int>>& rooms)
    {
        visited[room] = true;
        
        for (int j = 0; j < rooms[room].size(); j++)
        {
            int key = rooms[room][j];
            s.insert(key);
            if (!visited[key])
            {
                dfs(key, visited, s, rooms);
            }
        }
    }
};