/* 
 * Problem: 418. Sentence Screen Fitting [medium]
 * Source : https://leetcode.com/problems/sentence-screen-fitting/description/
 * Solver : Baur Krykpayev
 * Date   : 06/21/2018
 */
 
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) 
    {
        string sen;
        for (string word : sentence)
        {
            sen += word;
            sen += " ";
        }
        
        int cnt = 0;
        int n = sen.size();
       
        for (int i = 0; i < rows; i++)
        {
            cnt += cols;
            
            if (sen[cnt%n] == ' ')
            {
                cnt++;
            }
            else
            {
                while (cnt > 0 && sen[(cnt-1)%n] != ' ')
                {
                    cnt--;
                }
            }
        }
        
        return cnt/n; 
    }
};