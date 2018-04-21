/* 
 * Problem: 762. Prime Number of Set Bits in Binary Representation [easy]
 * Source : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/
 * Solver : Baur Krykpayev
 * Date   : 4/21/2018
 */

class Solution {
public:
    int countPrimeSetBits(int L, int R) 
    {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19,23};
        int count = 0;
        
        for (int i = L; i <= R; i++)
        {
            int num = i;
            int bits = 0;
            while (num)
            {
                bits += num&1;
                num >>= 1;
            }
            
            if (primes.count(bits)){count++;}
        }
        
        return count;
    }
};