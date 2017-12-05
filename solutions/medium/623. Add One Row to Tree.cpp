/* 
 * Problem: 623. Add One Row to Tree[medium]
 * Source : https://leetcode.com/problems/add-one-row-to-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 12/05/2017
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) 
    {
        if (d == 1)
        {
            TreeNode* head = new TreeNode(v);
            head->left = root;
            return head;
        }
        
        int level = 2;
        helper(root,v,d,level);
     
        return root;
    }

private:
    
    void helper(TreeNode* root, int v, int d, int level)
    {
        if (!root)
        {
            return;
        }
        else if (d == level)
        {
            TreeNode* left = new TreeNode(v);
            TreeNode* right = new TreeNode(v);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
            return;
        }
        else
        {
            helper(root->left,v,d,level+1);
            helper(root->right,v,d,level+1);  
        }
    }
};