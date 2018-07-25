/* 
 * Problem: 872. Leaf-Similar Trees [easy]
 * Source : https://leetcode.com/problems/leaf-similar-trees/description/
 * Solver : Baur Krykpayev
 * Date   : 07/24/2018
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> leaves1;
        vector<int> leaves2;
        helper(root1, leaves1);
        helper(root2, leaves2);
        
        return leaves1 == leaves2;
    }
    
private:
    void helper(TreeNode* root, vector<int>& ans)
    {
        if (!root->left && !root->right)
        {
            ans.push_back(root->val);
            return;
        }   
        
        if (root->left)
        {
            helper(root->left, ans);
        }
        
        if (root->right)
        {
            helper(root->right, ans);
        }
    }
};