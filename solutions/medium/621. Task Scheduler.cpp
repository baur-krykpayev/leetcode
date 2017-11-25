/* 
 * Problem: 621. Task Scheduler[medium]
 * Source : https://leetcode.com/problems/task-scheduler/description/
 * Solver : Baur Krykpayev
 * Date   : 11/25/2017
 */
 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<pair<int,int>> taskData(25, make_pair(0,0));
        int count = 0;
        bool done = false;
        
        for (auto task: tasks)
        {
            taskData[task - 65].first++;
        }
        
        while(!done)
        {
            int indicator = findMaxFreq(taskData, n);
            
            if (!indicator)
            {
                done = true;
            }
            else
            {
                count++;
            }
        }
        
        return count;
    }
    
private:
    int findMaxFreq(vector<pair<int,int>> &taskData, int n)
    {
        int freq = -1;
        int maxI = 0;
        bool cont = false;
        for (int i = 0; i < taskData.size(); i++)
        {
            if (taskData[i].first > 0)
            {
                cont = true;
                if (freq < taskData[i].first && !taskData[i].second)
                {
                    freq = taskData[i].first;
                    maxI = i;
                }
            }
        }
        
        for (int i = 0; i < taskData.size(); i++)
        {
            if (taskData[i].second)
            {
                taskData[i].second--;    
            }
        }     
        
        if (!cont)
        {
            freq = 0;
        }
        else if (freq > 0)
        { 
            taskData[maxI].first--;
            taskData[maxI].second = n;
        }
       
        return freq;
    }
};