/* 
 * Problem: 449. Serialize and Deserialize BST [medium]
 * Source : https://leetcode.com/problems/serialize-and-deserialize-bst/description/
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string ret;
        if (!root){return ret;}
        
        ret = to_string(root->val) + "#";
        ret += serialize(root->left);
        ret += serialize(root->right);
        
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        int pos = 0;
        return deserialize(data, INT_MAX, pos);
    }
    
private:
    TreeNode* deserialize(string& data, int limit, int& pos)
    {
        
        if (data.size() == pos) {return NULL;}
        
        int num = 0;
        int i = pos;
        while (isdigit(data[i]))
        {
            int temp = data[i] - '0';
            num = num*10 + temp;
            i++;
        }
        i++; // skip the delimeter
        
        if (num > limit) {return NULL;}
        pos = i;
        TreeNode* root = new TreeNode(num);
        root->left =  deserialize(data, num, pos);
        root->right = deserialize(data, limit, pos);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));