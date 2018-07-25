/* 
 * Problem: 559. Maximum Depth of N-ary Tree [easy]
 * Source : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 07/23/2018
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) 
    {
        if (!root){return 0;}
        
        int m = 0;
        
        for (Node* node : root->children)
        {
            m = max(m, maxDepth(node));
        }
        
        return m+1;
    }
};