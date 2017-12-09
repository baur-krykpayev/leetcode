/* 
 * Problem: 56. Merge Intervals[medium]
 * Source : https://leetcode.com/problems/merge-intervals/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
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
        
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<Interval> ret;
        if(!intervals.size()){return ret;}
        sort(intervals.begin(), intervals.end(), less_than_key()); 
     
        Interval *temp =  new Interval();
        bool found = true;
        
        for (int i = 0; i < intervals.size(); i++ )
        {
            if (found)
            {
                temp->start = intervals[i].start;
                temp->end = intervals[i].end;
                found = false;
            }
            else
            {
                if (temp->end >= intervals[i].start)
                {
                    temp->end = (temp->end < intervals[i].end) ? intervals[i].end : temp->end;
                }
                else
                {
                    ret.push_back(*temp);
                    i--;
                    found = true;
                }
            }
        }
        
        ret.push_back(*temp);
        return ret;       
    }
    
private:

    struct less_than_key
    {
        inline bool operator() (const Interval& int1, const Interval& int2)
        {
            return (int1.start < int2.start);
        }
    };    
};