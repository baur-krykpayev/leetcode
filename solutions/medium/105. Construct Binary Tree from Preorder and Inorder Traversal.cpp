/* 
 * Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal [medium]
 * Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int,int> map;
        
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i; 
        }
        
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
        return root;
    }

private:
    
    TreeNode* build(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end, unordered_map<int, int>& map)
    {
        if (p_start > p_end || i_start > i_end)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[p_start]);
        int pivot = map[root->val];
        
        root->left  = build(preorder, p_start + 1, p_start + pivot - i_start, inorder, i_start, pivot - 1, map);
        root->right = build(preorder, p_start + pivot - i_start + 1 , p_end, inorder, pivot + 1, i_end, map);
    
        return root;
    }
};