/* 
 * Problem: 677. Map Sum Pairs[medium]
 * Source : https://leetcode.com/problems/map-sum-pairs/description/
 * Solver : Baur Krykpayev
 * Date   : 02/08/2018
 */
 
#define ALPHABET_SIZE 26

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        root = getTrieNode();
    }
    
    void insert(string word, int val) 
    {
        TrieNode* end = searchPrefix(word);
        int sub = 0;
        
        if (end != NULL)
        {
            sub = end->sum;
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (end->children[i] != NULL)
                {
                    sub = 0;
                }    
            }       
        }
                
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            int index = tolower(word[i]) - 'a';
            
            if (cur->children[index] == NULL)
            {
                cur->children[index] = getTrieNode();
            }
          
            cur->children[index]->sum += (val-sub);
            cur = cur->children[index];
        }
        
        cur->wordEnd = true;
    }
    
    int sum(string prefix) 
    {
        int retVal = 0;
        TrieNode* cur = searchPrefix(prefix);
        if (cur)
        {
            retVal = cur->sum;
        }
        return retVal;
    }

private:
    /** @brief trie node structure */
    typedef struct TrieNode
    {
        struct TrieNode *children[ALPHABET_SIZE];
        int sum;
        bool wordEnd;
    };
    
    TrieNode* root;
           
    /** @brief Returns new trie node */
    TrieNode* getTrieNode(void)
    {
        TrieNode* retNode = new TrieNode;
        retNode->wordEnd = false;
        retNode->sum = 0;
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            retNode->children[i] = NULL;
        }
        
        return retNode;
    }
    
    /** @brief Returns prefix node if it exists. */
    TrieNode* searchPrefix(string word) 
    {
        TrieNode* cur = root;
        
        for (int i = 0; i < word.length(); i++)
        {
            int index = tolower(word[i]) - 'a';
            if (!cur->children){return NULL;}
            cur = cur->children[index];
        }
        
        return cur;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */