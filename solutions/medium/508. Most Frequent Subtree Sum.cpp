/* 
 * Problem: 508. Most Frequent Subtree Sum [medium]
 * Source : https://leetcode.com/problems/most-frequent-subtree-sum/description/
 * Solver : Baur Krykpayev
 * Date   : 3/21/2018
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int> ret;
        sumNodes(root);
        
        int m = 0;
        for (auto it : map)
        {
            if (it.second > m) 
            {
                m = it.second;
            }
        }
        
        for (auto it : map)
        {
            if (it.second == m) 
            {
                ret.push_back(it.first);
            }
        }
        
        return ret;
    }
    
private:
    unordered_map<int, int> map;
    
    int sumNodes(TreeNode* root)
    {
        if (!root) {return 0;}
        
        int s = 
            sumNodes(root->left) + 
            sumNodes(root->right) +
            root->val;
        
        map[s]++;
        
        return s;
    }
};