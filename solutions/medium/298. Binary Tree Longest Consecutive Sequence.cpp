/* 
 * Problem: 298. Binary Tree Longest Consecutive Sequence [medium]
 * Source : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 * Solver : Baur Krykpayev
 * Date   : 06/30/2018
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
    int longestConsecutive(TreeNode* root) 
    {
        helper(root, INT_MIN, 0);
        return ans;
    }
    
private:
    int ans = 0;
    
    void helper(TreeNode* root, int prev, int cnt)
    {
        if (!root) {return;}
        cnt = (root->val == prev + 1) ? cnt+1 : 1;
        ans = max(ans, cnt);
        helper(root->left, root->val, cnt);
        helper(root->right, root->val, cnt);   
    }
};