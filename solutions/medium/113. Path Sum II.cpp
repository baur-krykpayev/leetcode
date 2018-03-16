/* 
 * Problem: 113. Path Sum II [medium]
 * Source : https://leetcode.com/problems/path-sum-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 3/15/2018
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> ret;
        vector<int> temp;
        helper(root, sum, temp, ret);
        return ret;
    }

private:
    void helper(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& ret)
    {
        if (!root) {return;}
        temp.push_back(root->val);
        if (root->val == sum && !root->right && !root->left)
        {
            ret.push_back(temp);
        }
        helper(root->left, sum - root->val, temp, ret);
        helper(root->right, sum - root->val, temp, ret);
        temp.pop_back();
    }
};