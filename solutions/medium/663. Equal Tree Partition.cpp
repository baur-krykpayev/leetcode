/* 
 * Problem: 663. Equal Tree Partition [medium]
 * Source : https://leetcode.com/problems/equal-tree-partition/description/
 * Solver : Baur Krykpayev
 * Date   : 4/22/2018
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
    bool checkEqualTree(TreeNode* root) 
    {
        unordered_map<int,int> hash;
        int s =  findSum(root, hash);
        if (!s) {return hash[s] > 1;}
        return s%2 == 0 && hash.count(s/2); 
    }
    
    int findSum(TreeNode* root, unordered_map<int, int>& hash)
    {
        if (!root) {return 0;}
        int s =  root->val + findSum(root->left, hash) + findSum(root->right, hash);
        hash[s]++;
        return s;
    }
};