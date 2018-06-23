/* 
 * Problem: 501. Find Mode in Binary Search Tree [easy]
 * Source : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 06/23/2018
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
    vector<int> findMode(TreeNode* root) 
    {
        inorder(root, false);
        cnt = 0;
        cmp = INT_MIN;
        inorder(root, true);
        return ret;
    }
    
private:
    int maxCnt = 0;
    int cnt = 0;
    int cmp = INT_MIN;
    vector<int> ret;
    
    void getFreq(int val)
    {
        if (val != cmp)
        {
            cnt = 0;
            cmp = val;
        }
        
        cnt++;
        maxCnt = max(maxCnt, cnt);
    }
    
    void getMode(int val)
    {
        if (val != cmp)
        {
            cnt = 0;
            cmp = val;
        }
        
        if (++cnt == maxCnt)
        {
            ret.push_back(val);
        }
    }
    
    void inorder(TreeNode* root, bool final)
    {
        if (!root) {return;}
        inorder(root->left, final);
        
        if (!final)
        {
            getFreq(root->val);
        }
        else
        {
            getMode(root->val);
        }
        
        inorder(root->right, final);
    }
};