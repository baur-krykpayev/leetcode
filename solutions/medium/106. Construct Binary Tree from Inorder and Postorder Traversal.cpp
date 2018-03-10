/* 
 * Problem: 106. Construct Binary Tree from Inorder and Postorder Traversal [medium]
 * Source : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 * Solver : Baur Krykpayev
 * Date   : 3/9/2018
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
         unordered_map<int,int> map;
        
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i; 
        }
        
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, map);
        return root;
    }

private:
    
    TreeNode* build(vector<int>& postorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end, unordered_map<int, int>& map)
    {
        if (p_start > p_end || i_start > i_end)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[p_end]);
        int pivot = map[root->val];
    
        root->left  = build(postorder, p_start, p_start + pivot - i_start -1, inorder, i_start, pivot - 1, map);
        root->right = build(postorder, p_start + pivot - i_start, p_end-1, inorder, pivot + 1, i_end, map);
    
        return root;
    }
};