/* 
 * Problem: 662. Maximum Width of Binary Tree [medium]
 * Source : https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 3/19/2018
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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*, int>> cur;
        queue<pair<TreeNode*, int>> next;
        cur.push(make_pair(root, 1));
        int m = 0;
        
        while (!cur.empty() || !next.empty())
        {
            int l = cur.front().second;
      
            while(!cur.empty())
            {
                TreeNode* node = cur.front().first;
                int temp = cur.front().second;
                cur.pop();
                
                m = max(m, temp - l + 1);
                
                if (node->left)
                {
                    next.push(make_pair(node->left, 2*temp));
                }
                
                if (node->right)
                {
                    next.push(make_pair(node->right, 2*temp+1));
                }
            }
            
            cur.swap(next);
        }
        
        return m;
    }
    
};