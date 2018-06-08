/* 
 * Problem: 681. Next Closest Time [medium]
 * Source : https://leetcode.com/problems/next-closest-time/description/
 * Solver : Baur Krykpayev
 * Date   : 6/8/2018
 */

class Solution {
public:
    string nextClosestTime(string time) 
    {
        int h1 = time[0] - '0';
        int h2 = time[1] - '0';
        int m1 = time[3] - '0';
        int m2 = time[4] - '0';
        
        vector<int> sorted = {h1, h2, m1, m2};
        sort(sorted.begin(), sorted.end());
        int l = sorted[0];
        
        for (int n : sorted)
        {
            if (n > m2){return stringer(h1,h2,m1,n);}
        }
        
        for (int n : sorted)
        {
            if (n > 5) {break;}
            if (n > m1){return stringer(h1,h2,n,l);}
        }
        
        for (int n : sorted)
        {
            if (n > 3 && h1 == 2) {break;}
            if (n > h2){return stringer(h1,n,l,l);}
        }
        
        for (int n : sorted)
        {
            if (n > 2) {break;}
            if (n > h1){return stringer(n,l,l,l);}
        }
        
        return stringer(l,l,l,l);
    }
private:
    string stringer(int a, int b, int c, int d)
    {
        return to_string(a) + to_string(b) + ":" + to_string(c) + to_string(d);
    }
};