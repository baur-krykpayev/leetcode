/* 
 * Problem: 84. Largest Rectangle in Histogram [hard]
 * Source : https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 * Solver : Baur Krykpayev
 * Date   : 3/14/2018
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.push_back(0);
        stack<int> s;
        int m = 0;
        
        for (int i = 0; i < heights.size()+1; i++)
        {
            int h = heights[i];
            
            while (!s.empty() && h < heights[s.top()])
            {
                int temp = s.top();
                s.pop();

                int pos = s.empty() ? i : i - s.top()-1;
                m = max(m, heights[temp]*pos);                
            }
            
            if (s.empty() || h >= heights[s.top()])
            {
                s.push(i);
            }
        }
        
        return m;
    }
};