/* 
 * Problem: 94. Binary Tree Inorder Traversal[medium]
 * Source : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 * Solver : Baur Krykpayev
 * Date   : 11/19/2017
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
    vector<int> inorderTraversal(TreeNode* root) 
    {     
        stack<TreeNode*> sTemp;
        vector<int> retVec;
        if (!root)
        {
            return retVec;
        }
            
        TreeNode* current = root;
        sTemp.push(root);
        
        while (!sTemp.empty())            
        {
            if (current)
            {
                current = current->right;
            }
            else
            {
                current = sTemp.top();
                sTemp.pop();
                retVec.insert(retVec.begin(), current->val);
                current = current->left;
            }
            
            if(current)
            {
                sTemp.push(current);    
            }
        }  
        return retVec;
    }
};