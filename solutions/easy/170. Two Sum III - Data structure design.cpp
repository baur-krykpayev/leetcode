/* 
 * Problem: 170. Two Sum III - Data structure design [easy]
 * Source : https://leetcode.com/problems/two-sum-iii-data-structure-design/description/
 * Solver : Baur Krykpayev
 * Date   : 06/30/2018
 */
 
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) 
    {        
        nums[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) 
    {
        for(auto num : nums)
        {
            int temp = value - num.first;
            
            if (nums.count(temp))
            {
                if (num.second > 1 || temp != num.first)
                {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    unordered_map<int, int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */