/* 
 * Problem: 144. Binary Tree Preorder Traversal[medium]
 * Source : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * Solver : Baur Krykpayev
 * Date   : 3/4/2018
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        if (!root) {return ret;}
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);

            if (cur->right)
            {
                s.push(cur->right);
            }
            
            if (cur->left)
            {
                s.push(cur->left);
            }
        }
        
        return ret;
    }

};