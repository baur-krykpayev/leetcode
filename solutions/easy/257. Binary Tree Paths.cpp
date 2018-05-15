/* 
 * Problem: 257. Binary Tree Paths [easy]
 * Source : https://leetcode.com/problems/binary-tree-paths/description/
 * Solver : Baur Krykpayev
 * Date   : 5/14/2018
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ret;
        string temp;
        traverse(root, ret, temp);
        return ret;
    }
private:
    void traverse(TreeNode* root, vector<string>& ret,string temp)
    {
        if (!root){return;}
        temp += to_string(root->val);
        if (!root->left && !root->right)
        {
            ret.push_back(temp);
            return;
        }
        temp += "->";
        traverse(root->left,  ret, temp);
        traverse(root->right, ret, temp);
        return;
    }
};