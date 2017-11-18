/* 
 * Problem: 654. Maximum Binary Tree[medium]
 * Source : https://leetcode.com/problems/maximum-binary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 11/18/2017
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return findMaxIndex(nums, 0, nums.size());
    }
    
private:
    
    TreeNode* findMaxIndex(vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            return NULL;
        }
        int ind = maxIndex(nums, start, end);
        TreeNode* root = new TreeNode(nums[ind]);
        
        root->left = findMaxIndex(nums, start, ind);
        root->right = findMaxIndex(nums, ind + 1, end);
        
        return root;
    }
    
    int maxIndex(vector<int>& nums, int start, int end)
    {
        int maxInd = start;
        
        for (int index = start; index < end; index++)
        {
            if (nums[maxInd] < nums[index])
            {
                maxInd = index;
            }    
        }
        return maxInd;
    }
};