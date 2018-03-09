/* 
 * Problem: 145. Binary Tree Postorder Traversal [hard]
 * Source : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 * Solver : Baur Krykpayev
 * Date   : 3/8/2018
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
    vector<int> postorderTraversal(TreeNode* root) 
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
            
            if (cur->left){s.push(cur->left);}
            if (cur->right){s.push(cur->right);}
        }
        
        reverse(ret.begin(), ret.end());
        return ret;   
    }
};