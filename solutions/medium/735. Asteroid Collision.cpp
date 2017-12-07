/* 
 * Problem: 735. Asteroid Collision[medium]
 * Source : https://leetcode.com/problems/asteroid-collision/description/
 * Solver : Baur Krykpayev
 * Date   : 12/07/2017
 */
 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ret;
        stack<int> s;
        
        for (auto ast: asteroids)
        {
            if(ast > 0)
            {
                s.push(ast);
            }
            else
            {
                if(!s.empty())
                {
                    bool done = false;
                    while (!s.empty() && !done)
                    {
                        if (abs(ast) > s.top())
                        {
                            s.pop();                                   
                        }
                        else if (abs(ast) < s.top())
                        {
                            done = true;
                        }
                        else 
                        {
                            s.pop();
                            done = true;
                        }
                    }
                    
                    if (s.empty() && !done)
                    {
                        ret.push_back(ast);
                    }
                }
                else
                {
                    ret.push_back(ast);
                }
            }
        }
        
        vector<int> tempVec;
        while (!s.empty())
        {
            tempVec.push_back(s.top());
            s.pop();
        }

        for (int i = tempVec.size() - 1; i>=0; --i)
        {
            ret.push_back(tempVec[i]);
        }

        return ret;
    }
};