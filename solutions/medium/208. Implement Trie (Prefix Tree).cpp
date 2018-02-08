/* 
 * Problem: 208. Implement Trie (Prefix Tree)[medium]
 * Source : https://leetcode.com/problems/implement-trie-prefix-tree/description/
 * Solver : Baur Krykpayev
 * Date   : 02/07/2018
 */
 
#define ALPHABET_SIZE 26

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        root = getTrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            int index = tolower(word[i]) - 'a';
            if (cur->children[index] == NULL)
            {
                cur->children[index] = getTrieNode();
            }

            cur = cur->children[index];
        }
        
        cur->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            int index = tolower(word[i]) - 'a';
            if (!cur->children){return false;}
            cur = cur->children[index];
        }
        
        return (cur != NULL && cur->isEndOfWord);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < prefix.length(); i++)
        {
            int index = tolower(prefix[i]) - 'a';
            if (!cur->children){return false;}
            cur = cur->children[index];
        }
        
        return (cur != NULL);
    }
    
private:
    typedef struct TrieNode
    {
         struct TrieNode *children[ALPHABET_SIZE];

         // isEndOfWord is true if the node
         // represents end of a word
         bool isEndOfWord;
    };
    
    TrieNode* root;
            
    TrieNode* getTrieNode(void)
    {
        TrieNode* retNode = new TrieNode;
        retNode->isEndOfWord = false;
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            retNode->children[i] = NULL;
        }
        
        return retNode;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */