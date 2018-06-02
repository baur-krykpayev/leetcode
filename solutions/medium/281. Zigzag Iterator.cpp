/* 
 * Problem: 281. Zigzag Iterator [medium]
 * Source : https://leetcode.com/problems/zigzag-iterator/description/
 * Solver : Baur Krykpayev
 * Date   : 6/2/2018
 */

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
    {
        this->v1 = v1;
        this->v2 = v2;
        
        reverse = (v1.size()) ? true : false;
    }

    int next() 
    {
        int ret = 0;
        if (reverse)
        {
            ret = v1[i++];
            if (j < v2.size())
            {
                reverse = false;    
            }
            
        }
        else 
        {
            ret = v2[j++];
            if (i < v1.size())
            {
                reverse = true;    
            }
        }
        
        return ret;
    }

    bool hasNext() 
    {
        return (i < v1.size() || j < v2.size());
    }

private:
    vector<int> v1;
    vector<int> v2;
    bool reverse = false;
    int i = 0;
    int j = 0;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */