/* 
 * Problem: 384. Shuffle an Array[medium]
 * Source : https://leetcode.com/problems/shuffle-an-array/description/
 * Solver : Baur Krykpayev
 * Date   : 12/05/2017
 */
 

class Solution {
public:
    Solution(vector<int> nums) 
    {
        init = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        ret = init;

        for (int i = 0; i < ret.size(); i++)
        {
            // Pick a random index from 0 to i
            int j = rand() % (i+1);
            // Swap arr[i] with the element at random index
            swap(&ret[i], &ret[j]);
        }
        
        return ret;
    }
    
private:
    vector<int> ret;
    vector<int> init;
    
    // A utility function to swap to integers
    void swap (int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */