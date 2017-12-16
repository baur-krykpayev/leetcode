/* 
 * Problem: 11. Container With Most Water[medium]
 * Source : https://leetcode.com/problems/container-with-most-water/description/
 * Solver : Baur Krykpayev
 * Date   : 12/16/2017
 */

class Solution {
public:
    int maxArea(vector<int>& height)       
    {        
        int area = 0;
        int hMax = 0;
        
        for (int i = 0; i < height.size();i++)
        {
            if (height[i] > hMax)
            {
                hMax = height[i];
                int right = height.size() - 1;

                while (i < right)
                {
                    int h = min(height[i], height[right]);
                    
                    if (area < h * (right - i))
                    {
                        area = h*(right - i);
                    }
            
                    right--;
                }        
            }
        }   
            
        return area;
    }
};