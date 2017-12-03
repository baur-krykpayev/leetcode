/* 
 * Problem: 655. Print Binary Tree[medium]
 * Source : https://leetcode.com/problems/print-binary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 12/03/2017
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
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int height = findHeight(root);
        vector<vector<string>> ret (height, vector<string> (pow(2, height) - 1, ""));    
        placer(0, pow(2, height) - 2, 0, root, ret);                          
        return ret;
    }
    
private:
    
    // helper function to find height of the tree
    int findHeight(TreeNode* root) 
    {   
        if (!root) {return 0;}
        return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    
    // val placer helper function
    void placer(int r, int l, int level, TreeNode* root, vector<vector<string>> &ret)
    {
        if (r > l) {return;}
        
        if (root)
        {
            ret[level][(r+l)/2] = to_string(root->val);    
            placer(r, (r+l)/2 - 1, level + 1, root->left, ret);
            placer((r+l)/2 + 1, l, level + 1, root->right, ret);
        }        
    }
};