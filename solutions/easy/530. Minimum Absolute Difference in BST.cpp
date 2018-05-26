/* 
 * Problem: 530. Minimum Absolute Difference in BST [easy]
 * Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 * Solver : Baur Krykpayev
 * Date   : 5/26/2018
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
    int getMinimumDifference(TreeNode* root) 
    {
        m = INT_MAX;
        int prev = -1;
        traverse(root, prev);
        return m;
    }
private: 
    int m;
    
    void traverse(TreeNode* root, int& prev)
    {
        if (root->left) {traverse(root->left, prev);}
        if (prev >= 0){m = min(abs(root->val - prev), m);}
        prev = root->val;
        if (root->right){traverse(root->right, prev);}
    }
};