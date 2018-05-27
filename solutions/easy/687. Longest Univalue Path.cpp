/* 
 * Problem: 687. Longest Univalue Path [easy]
 * Source : https://leetcode.com/problems/longest-univalue-path/description/
 * Solver : Baur Krykpayev
 * Date   : 5/27/2018
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
    int longestUnivaluePath(TreeNode* root) 
    {
        helper(root);
        return ans;
    }
    
private:
    int ans = 0;
    int helper(TreeNode* root)
    {
        if (!root) {return 0;}
        int l =  helper(root->left);
        int r = helper(root->right);
        int left = 0; int right = 0;
        if (root->right && root->right->val == root->val)
        {
            right += r;
        }
        
        if (root->left && root->left->val == root->val)
        {
            left += l;
        }
        ans = max(left+right, ans);
        return max(left,right)+1;
    }
};