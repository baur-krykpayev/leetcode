/* 
 * Problem: 102. Binary Tree Level Order Traversal [medium]
 * Source : https://leetcode.com/problems/counting-bits/description/
 * Solver : Baur Krykpayev
 * Date   : 11/16/2017
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> retVec;
        vector<int> temp;
        queue<TreeNode*> currentQ;
        queue<TreeNode*> nextQ;
        
        if (!root)
        {
            return retVec;
        }
        
        currentQ.push(root);
      
        while(!currentQ.empty())
        {
            TreeNode* current = currentQ.front();
            currentQ.pop();
            
            if (current)
            {
                temp.push_back(current->val);
                nextQ.push(current->left);
                nextQ.push(current->right);    
            }
            
            if(currentQ.empty())
            {
                if(!temp.empty())
                {
                    retVec.push_back(temp);    
                }

                temp.clear();
                swap(currentQ,nextQ);
            }
        }
           
        return retVec;
    }
};