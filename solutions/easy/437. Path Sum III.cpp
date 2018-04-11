/* 
 * Problem: 437. Path Sum III [easy]
 * Source : https://leetcode.com/problems/path-sum-iii/description/
 * Solver : Baur Krykpayev
 * Date   : 4/10/2018
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
    int pathSum(TreeNode* root, int sum) 
    {
        int ret = 0;
        if (!root) {return ret;}
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            ret += helper(cur, sum);
            
            if (cur->left){q.push(cur->left);}
            if (cur->right){q.push(cur->right);}
        }
        
        return ret;
    }
    
private:
    int helper(TreeNode* root, int sum)
    {
        if (!root) {return 0;}
        int s = sum - root->val; 
        int left = helper(root->left, s);
        int right = helper(root->right, s);
        return left + right +((s) ? 0 : 1);
    }
};