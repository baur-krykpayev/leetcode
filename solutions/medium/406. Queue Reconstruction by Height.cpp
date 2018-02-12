/* 
 * Problem: 406. Queue Reconstruction by Height[medium]
 * Source : https://leetcode.com/problems/queue-reconstruction-by-height/description/
 * Solver : Baur Krykpayev
 * Date   : 02/12/2018
 */
 
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
    {
        vector<pair<int, int>> q;
        
        while (people.size())
        {
            vector<pair<int,int>> temp = 
                extractMaxs(people, findMax(people));
            
            sort(temp.begin(), temp.end(), [](auto &left, auto &right) 
            {return left.second < right.second;});
            
            for (int i = 0; i < temp.size(); i++)
            {
                int pos = temp[i].second;
                q.insert(q.begin() + pos,temp[i]);
            }
        }
        return q;
    }
private:

    // helper to find max height
    int findMax(vector<pair<int, int>>& people)
    {
        int maxVal = INT_MIN;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i].first > maxVal)
            {
                maxVal = people[i].first;
            }
        }
        return maxVal;
    }
    
    // helper to extract all pairs with max heights
    vector<pair<int,int>> extractMaxs(vector<pair<int, int>>& people, int m)
    {
        vector<pair<int,int>> ret;
        for (int i = people.size()-1; i>=0; i--)
        {
            if (m == people[i].first)
            {
                ret.push_back(people[i]);
                people.erase(people.begin()+i);
            }
        }
        return ret;
    }
};