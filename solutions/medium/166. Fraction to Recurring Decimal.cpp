/* 
 * Problem: 166. Fraction to Recurring Decimal[medium]
 * Source : https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 * Solver : Baur Krykpayev
 * Date   : 02/10/2018
 */
 
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if (denominator == 0){return "Can't divide by zero";}
        if (numerator == 0){return "0";}
       
        string ret;
        unordered_map<long,long> hash;
        
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
        {
            ret += '-';
        }
        long num = abs((long)numerator);
        long den = abs((long)denominator);
        long div = num%den;
        ret += to_string(num/den);
        if (!div){return ret;}
        ret += '.';

        while (div)
        {
            div *= 10;        
            if(hash.find(div) != hash.end())
            {
                ret.insert(hash[div],1, '(');
                ret +=')';
                break;
            } 
            hash[div] = ret.size();
            ret += to_string(div/den);
            div = div%den;        
        }
        return ret;       
    }
};