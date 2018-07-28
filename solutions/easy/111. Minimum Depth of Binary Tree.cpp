/* 
 * Problem: 111. Minimum Depth of Binary Tree [easy]
 * Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 07/28/2018
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) 
{
    if (!root) {return 0;}
    if (!root->left && !root->right) {return 1;}
    
    int l = INT_MAX;
    int r = INT_MAX;
    
    if (root->left)
    {
        l  = minDepth(root->left);    
    }
    
    if (root->right)
    {
        r  = minDepth(root->right);    
    }
    
    return (l < r ? l : r) + 1;
}