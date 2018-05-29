/* 
 * Problem: 447. Number of Boomerangs [easy]
 * Source : https://leetcode.com/problems/number-of-boomerangs/description/
 * Solver : Baur Krykpayev
 * Date   : 5/28/2018
 */

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) 
    {
        unordered_map<int, int> map;
        int cnt = 0;
        
        for (auto p : points)
        {
            map.clear();
            for (auto n : points)
            {
                int dist = pow((n.first - p.first),2) + pow((n.second - p.second),2);
                if (dist){map[dist]++;}
            }
            
            for (auto it : map)
            {
                if(it.second >1)
                {
                    cnt += it.second*(it.second-1);    
                }
            }
        } 
        
        return cnt;
    }
};