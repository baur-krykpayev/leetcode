/* 
 * Problem: 42. Trapping Rain Water [hard]
 * Source : https://leetcode.com/problems/trapping-rain-water/description/
 * Solver : Baur Krykpayev
 * Date   : 6/9/2018
 */

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int l = 0;
        int r = height.size()-1;
        int maxL = l;
        int maxR = r;
        int cnt = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (height[maxL] <= height[l])
                {
                    maxL = l;
                }
                else
                {
                    cnt += (height[maxL] - height[l]);
                }
                
                l++;
            }
            else
            {
                if (height[maxR] <= height[r])
                {
                    maxR = r;
                }
                else
                {
                    cnt += (height[maxR] - height[r]);
                }
                r--;
            }    
        }
        
        return cnt;
    }
};