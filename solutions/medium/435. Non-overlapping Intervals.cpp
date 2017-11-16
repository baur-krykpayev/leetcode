/* 
 * Problem: 435. Non-overlapping Intervals [medium]
 * Source : https://leetcode.com/problems/non-overlapping-intervals/description/
 * Solver : Baur Krykpayev
 * Date   : 11/16/2017
 */
 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
static int compare (struct Interval* a, struct Interval* b)
{
    return a->end - b->end;
}
int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize) 
{
    if (!intervalsSize)
    {
        return 0;
    }
    
    qsort(intervals, intervalsSize, sizeof(struct Interval*), compare);
        
    // select the shortest interval each time
    int end = intervals[0].end;
    int count = 0;
    
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i].start >= end)
        {
            count++;
            end = intervals[i].end;
        }
    }
    
    return intervalsSize - count - 1;
}