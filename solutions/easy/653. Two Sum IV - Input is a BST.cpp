/* 
 * Problem: 653. Two Sum IV - Input is a BST [easy]
 * Source : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 * Solver : Baur Krykpayev
 * Date   : 06/26/2018
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
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root) {return false;}

        if (hash.find(k - root->val) != hash.end())
        {
            return true;
        }
                    
        hash.insert(root->val);

        return  findTarget(root->left, k) || findTarget(root->right, k);
    }

private:
    unordered_set<int> hash;    
};