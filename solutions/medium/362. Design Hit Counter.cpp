/* 
 * Problem: 362. Design Hit Counter [medium]
 * Source : https://leetcode.com/problems/design-hit-counter/description/
 * Solver : Baur Krykpayev
 * Date   : 6/2/2018
 */

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) 
    {
        q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) 
    {
        while (!q.empty() && (timestamp - q.front()) >= 300)
        {
            q.pop();
        }
            
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */