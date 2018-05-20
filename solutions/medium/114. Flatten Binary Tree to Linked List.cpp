/* 
 * Problem: 114. Flatten Binary Tree to Linked List [medium]
 * Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 * Solver : Baur Krykpayev
 * Date   : 5/19/2018
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
    void flatten(TreeNode* root) 
    {
        if (!root) {return;}
        (void) helper(root);
    }

private:
    TreeNode* helper (TreeNode* root)
    {
        if (!root->left && !root->right)
        {
            return root;
        }
        TreeNode* saved = root->right;
        root->right = NULL;
    
        if (root->left)
        {
            root->right = helper(root->left);
            root->left = NULL;
        }
    
        if (saved)
        {
            TreeNode* cur  = root;       
            while (cur->right){cur = cur->right;}
            cur->right = helper(saved); 
        }
        
        return root;
    }
};