/* 
 * Problem: 515. Find Largest Value in Each Tree Row[medium]
 * Source : https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 * Solver : Baur Krykpayev
 * Date   : 02/16/2018
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
    vector<int> largestValues(TreeNode* root) 
    {
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        vector<int> maxRet;
        if (!root) {return maxRet;}
        cur.push(root);
        
        while (!cur.empty())
        {
            int m = INT_MIN;
            
            while (!cur.empty())
            {
                TreeNode* temp =  cur.front();
                cur.pop();
                
                if (temp->val > m) {m = temp->val;}
                
                if (temp->left) {next.push(temp->left);}
                
                if (temp->right) {next.push(temp->right);}
            }
            
            maxRet.push_back(m);    
            cur = next;
            while(!next.empty()){next.pop();}
        }
        return maxRet;
    }
};