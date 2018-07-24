/* 
 * Problem: 709. To Lower Case [easy]
 * Source : https://leetcode.com/problems/to-lower-case/description/
 * Solver : Baur Krykpayev
 * Date   : 07/23/2018
 */

char* toLowerCase(char* str) 
{
    char* begin = str;
    
    while (*str)
    {
        if ( 'A' <= *str && *str <= 'Z')
        {
            *str = *str + 32;
        }
        
        str++;
    }
    
    return begin;
}