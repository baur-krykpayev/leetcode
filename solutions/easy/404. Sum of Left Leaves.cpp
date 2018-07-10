/* 
 * Problem: 404. Sum of Left Leaves [easy]
 * Source : https://leetcode.com/problems/sum-of-left-leaves/description/
 * Solver : Baur Krykpayev
 * Date   : 07/09/2018
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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root) {return 0;}
        traverse(root->left, true);
        traverse(root->right, false);
        return sum;
    }
    
private:
    int sum = 0;
    
    void traverse(TreeNode* root, bool isLeft)
    {
        if (!root){return;}
        if (isLeft && !root->left && !root->right){sum += root->val;}
        traverse(root->left, true);
        traverse(root->right, false);
    }
};