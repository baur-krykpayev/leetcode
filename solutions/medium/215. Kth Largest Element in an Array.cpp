/* 
 * Problem: 215. Kth Largest Element in an Array[medium]
 * Source : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 02/04/2018
 */
 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        build_max_heap(nums);
        
        for(int i = 0; i < k; i++)
        {
            swap(nums[0], nums[heap_size-1]);
            heap_size--;
            max_heapify(nums, 0);
        }
            
        return nums[heap_size];
    }
private:
    int heap_size;

    inline int left(int pos)
    {
        return (pos << 1) + 1;    
    }

    inline int right(int pos)
    {
        return (pos << 1) + 2;    
    }
    
    void build_max_heap(vector<int>& nums)
    {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) -1; i>=0; i--)
        {
            max_heapify(nums,i);
        }
    }
    
    void max_heapify(vector<int>& nums, int pos)
    {
        int largest = pos;
        int l = left(pos);
        int r = right(pos);
        
        if (l < heap_size && nums[l] > nums[largest]) {largest = l;}
        if (r < heap_size && nums[r] > nums[largest]) {largest = r;}
        if (largest != pos)
        {
            swap(nums[largest], nums[pos]);
            max_heapify(nums, largest);
        }
    }
};