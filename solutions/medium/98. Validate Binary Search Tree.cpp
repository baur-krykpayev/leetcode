/* 
 * Problem: 98. Validate Binary Search Tree[medium]
 * Source : https://leetcode.com/problems/validate-binary-search-tree/description/
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
    bool isValidBST(TreeNode* root) 
    {
        if (!root) {return true;}
        stack<TreeNode*> l;
        stack<TreeNode*> r;
        return helper(root, l, r);
    }
private:
    
    // helper returns true if tree is valid, false otherwise
    bool helper(TreeNode* cur, stack<TreeNode*>& l, stack<TreeNode*>& r)
    {
        if (cur->left)
        {
            if ((cur->left->val < cur->val) &&
                (r.empty() || (cur->left->val > r.top()->val)))
            {
                l.push(cur);
                if(helper(cur->left, l, r)) {l.pop();}
                else{return false;}
            }
            else {return false;}   
        }
        
        if (cur->right)
        {
            if ((cur->right->val > cur->val) && 
                (l.empty() || (cur->right->val < l.top()->val)))
            {
                r.push(cur);
                if(helper(cur->right, l, r)) {r.pop();}
                else{return false;}
            }
            else {return false;}   
        }
        return true;
    }
};