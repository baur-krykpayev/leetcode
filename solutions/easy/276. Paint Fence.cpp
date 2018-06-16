/* 
 * Problem: 276. Paint Fence [easy]
 * Source : https://leetcode.com/problems/paint-fence/description/
 * Solver : Baur Krykpayev
 * Date   : 06/16/2018
 */
 
class Solution {
public:
    int numWays(int n, int k) 
    {
        if (!n) {return 0;}
        if (n==1) {return k;}
        int diff = k*(k-1), same = k;
        int total = diff+same;
        
        for (int i = 2; i < n; i++)
        {
            same = diff;
            diff = total*(k-1);
            total = diff + same;
        }
        
        return total;
    }
};