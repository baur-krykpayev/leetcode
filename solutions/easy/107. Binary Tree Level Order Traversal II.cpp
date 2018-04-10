/* 
 * Problem: 107. Binary Tree Level Order Traversal II [easy]
 * Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 4/9/2018
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ret;
        if (!root){return ret;}
        
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        cur.push(root);
        
        while(!cur.empty() || !next.empty())
        {
            vector<int> temp;
            while(!cur.empty())
            {
                TreeNode* node = cur.front();
                cur.pop();
                
                if (node->left){next.push(node->left);}
                if (node->right){next.push(node->right);}
                temp.push_back(node->val);
            }
            
            ret.push_back(temp);
            cur.swap(next);
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};