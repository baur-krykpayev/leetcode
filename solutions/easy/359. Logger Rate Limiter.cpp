/* 
 * Problem: 359. Logger Rate Limiter [easy]
 * Source : https://leetcode.com/problems/logger-rate-limiter/description/
 * Solver : Baur Krykpayev
 * Date   : 06/13/2018
 */
 
class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {hash.clear();}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (hash.find(message) == hash.end() ||
            (timestamp - hash[message] >= 10))
        {
            hash[message] = timestamp;
            return true;
        }
        
        return false;
    }
    
private:
    unordered_map<string, int> hash;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */