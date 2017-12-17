/* 
 * Problem: 54. Spiral Matrix[medium]
 * Source : https://leetcode.com/problems/spiral-matrix/description/
 * Solver : Baur Krykpayev
 * Date   : 12/16/2017
 */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ret;
        if (!matrix.size()) {return ret;}
        
        int rows = matrix.size()-1;
        int cols = matrix[0].size();
        DIRECTION_STATE state = STATE_RIGHT;
        int row = 0;
        int col = 0;
        
        while(ret.size() != matrix.size() * matrix[0].size())
        {
            switch(state)
            {
                case(STATE_RIGHT):
                {
                    for (int i = 0; i < cols; i++)
                    {
                        ret.push_back(matrix[row][col++]);
                    }
                    row++; col--; cols--; 
                    state = STATE_DOWN;
                    break;
                }
                    
                case(STATE_DOWN):
                {
                    for (int i = 0; i < rows; i++)
                    {
                        ret.push_back(matrix[row++][col]);
                    } 
                    col--; row--; rows--;
                    state = STATE_LEFT;
                    break;
                }
                    
                case(STATE_LEFT):
                {
                    for (int i = 0; i < cols; i++)
                    {
                        ret.push_back(matrix[row][col--]);
                    }
                    col++; row--; cols--;             
                    state = STATE_UP;
                    break;
                }
                    
                case(STATE_UP):
                {
                    for (int i = 0; i < rows; i++)
                    {
                        ret.push_back(matrix[row--][col]);
                    }
                    row++; col++; rows--;
                    state = STATE_RIGHT;
                    break;
                }
                default: {break;}            
            }
        }
         
        return ret;           
    }
    
private:
    typedef enum
    {
        STATE_RIGHT = 0,
        STATE_DOWN,
        STATE_LEFT,
        STATE_UP
    } DIRECTION_STATE;  
};