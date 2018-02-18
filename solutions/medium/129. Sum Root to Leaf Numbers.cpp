/* 
 * Problem: 129. Sum Root to Leaf Numbers[medium]
 * Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Solver : Baur Krykpayev
 * Date   : 2/18/2018
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
    int sumNumbers(TreeNode* root) 
    {
        return helper(root, 0);
    }
    
private:
    int helper(TreeNode* node, int sum)
    {
        if(!node) {return 0;}
        if(!node->left && !node->right)
        {
            return sum + node->val;
        }
        return helper(node->left, (sum + node->val) * 10)
            + helper(node->right, (sum + node->val) * 10);
    }
};