/* 
 * Problem: 199. Binary Tree Right Side View [medium]
 * Source: https://leetcode.com/problems/binary-tree-right-side-view/description/
 * Solver: Baur Krykpayev
 * Date  : 11/16/2017
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
    vector<int> rightSideView(TreeNode* root) 
    {    
        traverseLevels(root, 1);

        return retVec;
    }
private:
    
    vector<int> retVec;
    
    void traverseLevels(TreeNode* root, int level)
    {
        if (!root)
        {
            return;
        }
        
        if (retVec.size() < level)
        {
            // we are first time on this level
            retVec.push_back(root->val);
        }
        
        traverseLevels(root->right, level + 1);
        traverseLevels(root->left, level + 1);
    } 
};