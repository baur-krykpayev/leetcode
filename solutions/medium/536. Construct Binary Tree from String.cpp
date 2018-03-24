/* 
 * Problem: 536. Construct Binary Tree from String [medium]
 * Source : https://leetcode.com/problems/construct-binary-tree-from-string/description/
 * Solver : Baur Krykpayev
 * Date   : 3/23/2018
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
    TreeNode* str2tree(string s) 
    {
        if (s==""){return NULL;}
        int pos = 0;
        return build(s, pos);
    }
    
    TreeNode* build(string& s, int& pos)
    {
        string temp;
        
        while(s[pos] == '-' || isdigit(s[pos]))
        {
            temp += s[pos++];
        }
    
        TreeNode* root = new TreeNode(stoi(temp));
        
        if (s[pos] == '(')
        {
            pos++;
            root->left = build(s, pos);
            pos++;
        }
        
        if (s[pos] == '(')
        {
            pos++;
            root->right = build(s, pos);
            pos++;
        }
        
        return root;
    }
};