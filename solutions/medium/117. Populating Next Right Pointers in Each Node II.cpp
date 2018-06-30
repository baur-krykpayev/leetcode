/* 
 * Problem: 117. Populating Next Right Pointers in Each Node II [medium]
 * Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 06/30/2018
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
        TreeLinkNode* head = NULL;
        TreeLinkNode* cur = NULL;
        
        while (root)
        {
            
            while(root)
            {
                if (root->left)
                {
                    if (!head)
                    {
                        head = root->left;
                    }
                    else
                    {
                        cur->next = root->left;
                    }
                    
                    cur = root->left;
                }
                
                
                if (root->right)
                {
                    if (!head)
                    {
                        head = root->right;
                    }
                    else
                    {
                        cur->next = root->right;
                    }
                    
                    cur = root->right;
                }
                
                root = root->next;
            }
            
            root = head; head = NULL; cur = NULL;
        }
    }
};