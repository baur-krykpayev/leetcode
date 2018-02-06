/* 
 * Problem: 173. Binary Search Tree Iterator[medium]
 * Source : https://leetcode.com/problems/binary-search-tree-iterator/description/
 * Solver : Baur Krykpayev
 * Date   : 02/05/2018
 */
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = s.top();
        s.pop();
        if (ret->right)
        {
            pushStack(ret->right);
        }
        
        return ret->val;
    }
private:
    stack<TreeNode*> s;
    
    void pushStack(TreeNode *cur)
    {
        while (cur)
        {
            s.push(cur);
            cur = cur->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */