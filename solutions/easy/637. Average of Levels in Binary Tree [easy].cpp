/* 
 * Problem: 637. Average of Levels in Binary Tree [easy]
 * Source : https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 5/23/2018
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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ret;
        if (!root) {return ret;}
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            double ave = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = q.front(); q.pop();
                ave += cur->val;
                if (cur->left){q.push(cur->left);}
                if (cur->right){q.push(cur->right);}
            }
            ret.push_back(ave/size);
        }
        
        return ret;
    }
};