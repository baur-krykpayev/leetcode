/* 
 * Problem: 341. Flatten Nested List Iterator[medium]
 * Source : https://leetcode.com/problems/flatten-nested-list-iterator/description/
 * Solver : Baur Krykpayev
 * Date   : 02/12/2018
 */
 
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        pushVec(nestedList);
    }

    int next() 
    {
        int ret = s.top().getInteger();
        s.pop();
        return ret;
    }

    bool hasNext() 
    {
        while(!s.empty())
        {
            NestedInteger temp = s.top();
            if(temp.isInteger()){return true;}
            s.pop();
            pushVec(temp.getList());
        }
        return false;
    }
private: 
    stack<NestedInteger> s;
    
    void pushVec(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size()-1; i >=0; i--)
        {
            s.push(nestedList[i]);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */