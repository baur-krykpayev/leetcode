/* 
 * Problem: 299. Bulls and Cows [medium]
 * Source : https://leetcode.com/problems/bulls-and-cows/description/
 * Solver : Baur Krykpayev
 * Date   : 06/17/2018
 */
 
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        unordered_map<char, int> hash;
        int bulls = 0, cows = 0;
        
        for (int i = 0; i < secret.length() && i < guess.length(); i++)
        {
            if(secret[i] == guess[i])
            {
                bulls++;
                secret[i] = 'S';
                guess[i]  = 'G';
             }
        }
        
        for (char c : secret) {hash[c]++;}
        
        for (char c : guess)
        {
            if (hash[c])
            {
                cows++;
                hash[c]--;
            }
        }
        
        return to_string(bulls)+"A"+ to_string(cows) + "B";
    }
};