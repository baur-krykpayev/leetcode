/* 
 * Problem: 110. Balanced Binary Tree [easy]
 * Source : https://leetcode.com/problems/balanced-binary-tree/description/
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

static int helper(struct TreeNode* root)
{
    if (!root) {return 0;}
    
    int l = helper(root->left);
    int r = helper(root->right);
        
    if (l == -1 || r == -1 || abs(l-r) > 1)
    {
        return -1;
    }
    
    return ((l > r) ? l : r)+1;
}
    
bool isBalanced(struct TreeNode* root) 
{
    return helper(root) != -1;
}

