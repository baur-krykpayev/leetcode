/* 
 * Problem: 165. Compare Version Numbers [medium]
 * Source : https://leetcode.com/problems/compare-version-numbers/description/
 * Solver : Baur Krykpayev
 * Date   : 07/22/2018
 */

int compareVersion(char* version1, char* version2) 
{
    char* v1 = version1;
    char* v2 = version2;
    int num1 = 0;
    int num2 = 0;
    
    while (1)
    { 
        num1 = 0; num2 = 0;
        while (*v1 != '.' && *v1)
        {
            num1 = 10*num1 + *v1 - '0';
            v1++;
        }
        
        while (*v2 != '.' && *v2)
        {
            num2 = 10*num2 + *v2 - '0';
            v2++;
        }
        
        if (*v1 == '.' && *v2 == '.')
        {
            if (num1 > num2){return 1;}
            else if (num1 < num2) {return -1;}
            else
            {
                v1++; v2++; // skip both
            }
        }
        else if (!*v1 && !*v2)
        {
            if (num1 > num2){return 1;}
            else if (num1 < num2) {return -1;}
            else {return 0;}
        }
        else if (*v1 == '.' && !*v2)
        {
            if (num1 > num2){return 1;}
            else if (num1 < num2) {return -1;}
            else{v1++;}
        }
        else if (!*v1 && *v2 == '.')
        {
            if (num1 > num2){return 1;}
            else if (num1 < num2) {return -1;}
            else {v2++;}
        }    
    }
    
    return 0;   
}