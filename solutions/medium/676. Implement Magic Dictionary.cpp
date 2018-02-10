/* 
 * Problem: 676. Implement Magic Dictionary[medium]
 * Source : https://leetcode.com/problems/implement-magic-dictionary/description/
 * Solver : Baur Krykpayev
 * Date   : 02/09/2018
 */
 
#define ALPHABET_SIZE 26

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() 
    {
        root = getTrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) 
    {
        for (int i = 0; i < dict.size(); i++)
        {
            insert(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < word.size(); i++) 
        {
            int index = word[i];

            for (int j = 0; j < ALPHABET_SIZE; j++) 
            {
                if (index == j + 'a') {continue;}
                word[i] = j + 'a';
                if (searchNormal(word)){return true;}
            }
            word[i] = index;
        }
        return false;
    }

private:
    /** @brief trie node structure */
    typedef struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        bool wordEnd;
    };
    
    TrieNode* root;
    
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
        cur->wordEnd = true;
    }
    
    /** @brief Returns new trie node */
    TrieNode* getTrieNode(void)
    {
        TrieNode* retNode = new TrieNode;
        retNode->wordEnd = false;
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            retNode->children[i] = NULL;
        }
        
        return retNode;
    }
    
    bool searchNormal(string word) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            int index = tolower(word[i]) - 'a';
            if (!cur->children[index]){return false;}
            cur = cur->children[index];
        }
        
        return (cur != NULL && cur->wordEnd);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */