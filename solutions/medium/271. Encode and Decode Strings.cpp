/* 
 * Problem: 271. Encode and Decode Strings [medium]
 * Source : https://leetcode.com/problems/encode-and-decode-strings/description/
 * Solver : Baur Krykpayev
 * Date   : 06/21/2018
 */
 
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        string ret;
        
        for (string s : strs)
        {
            ret += to_string(s.length());
            ret += "#";
            ret += s;
        }
        
        return ret;
    }s

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> ret;
    
        int  i = 0;
        while (i < s.length())
        {
            int del = s.find_first_of('#', i);
            int len = stoi(s.substr(i, del-i));
            i = del + 1;
            ret.push_back(s.substr(i, len));
            i += len;
        }
    
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));