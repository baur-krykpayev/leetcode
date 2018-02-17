/* 
 * Problem: 513. Find Bottom Left Tree Value[medium]
 * Source : https://leetcode.com/problems/find-bottom-left-tree-value/description/
 * Solver : Baur Krykpayev
 * Date   : 2/17/2018
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
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        int ret = 0;
        if (!root) {return ret;}
        cur.push(root);
        
        while (!cur.empty())
        {
            ret = cur.front()->val;
            while (!cur.empty())
            {
                TreeNode* temp =  cur.front();
                cur.pop();
                if (temp->left) {next.push(temp->left);}
                if (temp->right) {next.push(temp->right);}
            }
            cur = next;
            while(!next.empty()){next.pop();}
        }
        return ret;
    }
};