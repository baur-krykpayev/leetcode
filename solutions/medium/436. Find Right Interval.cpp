/* 
 * Problem: 436. Find Right Interval[medium]
 * Source : https://leetcode.com/problems/find-right-interval/description/
 * Solver : Baur Krykpayev
 * Date   : 11/16/2017
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
    vector<int> findRightInterval(vector<Interval>& intervals) 
    {
        map<int,int> mapIndex;
        vector<int> retVec;
        
        for (int i = 0; i < intervals.size(); i++)
        {
            mapIndex.insert(pair<int,int>(intervals[i].start, i));
        }
        
        for (int i = 0; i < intervals.size(); i++)
        {
            map<int,int>::iterator it = mapIndex.lower_bound(intervals[i].end);
            
            if (it == mapIndex.end())
            {
                retVec.push_back(-1);
            }
            else
            {
                retVec.push_back(it->second);
            }
        }
        
         return retVec;
    }
};