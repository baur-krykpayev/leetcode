/* 
 * Problem: 728. Self Dividing Numbers [easy]
 * Source : https://leetcode.com/problems/self-dividing-numbers/description/
 * Solver : Baur Krykpayev
 * Date   : 4/11/2018
 */

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> ret;
        
        for (int i = left; i <= right; i++)
        {
            int num = i;
            bool non = false;
            
            while(num && !non)
            {
                int cur = num%10;
                if (!cur || i%cur){non = true;}
                num /= 10;
            }
            
            if (!non) {ret.push_back(i);}
        }
        
        return ret;
    }
};