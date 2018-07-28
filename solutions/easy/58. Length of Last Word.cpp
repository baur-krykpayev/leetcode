/* 
 * Problem: 58. Length of Last Word [easy]
 * Source : https://leetcode.com/problems/length-of-last-word/description/
 * Solver : Baur Krykpayev
 * Date   : 07/28/2018
 */

int lengthOfLastWord(char* s) 
{
    if (!*s) {return 0;}
    int l = 0;
    int ans = 0;
    
    while(*s)
    {
        if (*s == ' ')
        {
            if (l) {ans = l;}
            l=0;
        }
        else{l++;}
        s++;
    }
    
    return (l) ? l : ans;
}

