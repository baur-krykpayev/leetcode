/* 
 * Problem: 252. Meeting Rooms [easy]
 * Source : https://leetcode.com/problems/meeting-rooms/description/
 * Solver : Baur Krykpayev
 * Date   : 6/4/2018
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
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 1 ; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i-1].end)
            {
                return false;
            }
        }
        
        return true;
    }
    
private: 
    static bool comp(Interval& a, Interval& b)
    {
        return a.start < b.start;
    }
};