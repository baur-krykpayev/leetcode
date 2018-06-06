/* 
 * Problem: 253. Meeting Rooms II [medium]
 * Source : https://leetcode.com/problems/meeting-rooms-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 6/5/2018
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        int rooms = 0;
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq; 
            
        for (auto in : intervals)
        {
            if (pq.size() && in.start >= pq.top())
            {
                pq.pop();
            }
            
            pq.push(in.end);
        }     
        
        return pq.size();
    }
private: 
    static bool comp(Interval& a, Interval& b)
    {
        return a.start < b.start;
    }
};