/* 
 * Problem: 222. Count Complete Tree Nodes [medium]
 * Source : https://leetcode.com/problems/count-complete-tree-nodes/description/
 * Solver : Baur Krykpayev
 * Date   : 06/23/2018
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
    int countNodes(TreeNode* root) 
    {
        if (!root) {return 0;}
        int l = 0, r = 0;
        TreeNode* cur = root;
        
        while (cur)
        {
            cur = cur->left;
            l++;
        }
        
        cur = root;
        
        while (cur)
        {
            cur = cur->right;
            r++;
        }
        
        if (l == r) {return pow(2, l)-1;}
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};