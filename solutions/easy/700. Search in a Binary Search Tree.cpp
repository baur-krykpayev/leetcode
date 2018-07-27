/* 
 * Problem: 700. Search in a Binary Search Tree [easy]
 * Source : https://leetcode.com/problems/search-in-a-binary-search-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 07/26/2018
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) 
{
    if (!root) {return NULL;}
    
    if (root->val == val)
    {
        return root;
    }
    else if (val > root->val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);        
    }
    
    return NULL;
}