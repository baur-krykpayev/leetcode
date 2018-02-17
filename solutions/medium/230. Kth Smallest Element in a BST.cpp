/* 
 * Problem: 230. Kth Smallest Element in a BST[medium]
 * Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 * Solver : Baur Krykpayev
 * Date   : 2/17/2018
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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> nodes;
        TreeNode* cur = root;
        int ret = 0;
        
        while(!nodes.empty() || cur)
        {
            while(cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            
            cur = nodes.top();
            nodes.pop();
            k--;
            if (!k) 
            { 
                ret = cur->val;
                break;
            }
            cur = cur->right;
        }
        return ret;
    }
};