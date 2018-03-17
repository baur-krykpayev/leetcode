/* 
 * Problem: 116. Populating Next Right Pointers in Each Node[medium]
 * Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 * Solver : Baur Krykpayev
 * Date   : 3/17/2018
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if (!root){return;}
       
        TreeLinkNode *temp = root;
        
        while(root->left)
        {
            TreeLinkNode *temp = root;
            
            while(temp)
            {
                temp->left->next = temp->right;
                
                if (temp->next) 
                {
                    temp->right->next = temp->next->left;
                }
                
                temp=temp->next;
            }
            
            root = root->left;
        }
    }
};