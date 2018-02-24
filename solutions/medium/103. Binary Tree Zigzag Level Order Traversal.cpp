/* 
 * Problem: 103. Binary Tree Zigzag Level Order Traversal[medium]
 * Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 * Solver : Baur Krykpayev
 * Date   : 2/24/2018
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ret;
        if (!root) {return ret;}
        queue<TreeNode*> curLevel;
        queue<TreeNode*> nextLevel;
        bool shouldReverse = false;
        curLevel.push(root);  
       
        while (!curLevel.empty() || !nextLevel.empty())
        {
            vector<int> temp;
        
            while (!curLevel.empty())
            {
                TreeNode* cur = curLevel.front();
                curLevel.pop();

                if (cur->left) {nextLevel.push(cur->left);}
                if (cur->right) {nextLevel.push(cur->right);}
                temp.push_back(cur->val);
            }
            
            if (shouldReverse)
            {
                reverse(temp.begin(), temp.end());
                shouldReverse = false;
            }
            else
            {
                shouldReverse = true;   
            }
            
            ret.push_back(temp);
            swap(curLevel, nextLevel);
        }
        
        return ret;
    }
};