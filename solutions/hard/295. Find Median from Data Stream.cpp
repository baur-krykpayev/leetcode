/* 
 * Problem: 295. Find Median from Data Stream [hard]
 * Source : https://leetcode.com/problems/find-median-from-data-stream/description/
 * Solver : Baur Krykpayev
 * Date   : 06/23/2018
 */
 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);    
        }
        else
        {
            minHeap.push(num);    
        }
        
        if (maxHeap.size() == minHeap.size()+2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (maxHeap.size() == minHeap.size()-2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() 
    {
        if (maxHeap.size() == minHeap.size())
        {
            
            return maxHeap.empty() ? 0 : (maxHeap.top() + minHeap.top())/2.0;
        }
        else if (maxHeap.size() == minHeap.size()+1)
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }
private:
    priority_queue<int, vector<int>> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */