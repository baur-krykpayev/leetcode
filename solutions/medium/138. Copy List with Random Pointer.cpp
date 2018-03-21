/* 
 * Problem: 138. Copy List with Random Pointer [medium]
 * Source : https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * Solver : Baur Krykpayev
 * Date   : 3/21/2018
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        RandomListNode *copy = NULL;
        
        if (!head) { return copy;}
        
        unordered_map <RandomListNode*, RandomListNode*> map;
        copy = new RandomListNode(head->label);
        RandomListNode *cur = head->next;
        RandomListNode *curCopy = copy;
        map[head] = copy;
        
        // copy next
        while (cur)
        {
            RandomListNode *temp = new RandomListNode(cur->label);
            map[cur] = temp;
            curCopy->next = temp;
            curCopy = curCopy->next;
            cur = cur->next;
        }
        
        cur = head;
        curCopy = copy;
        
        // copy random  
        while (cur)
        {
            curCopy->random = map[cur->random];            
            curCopy = curCopy->next;
            cur = cur->next;
        }
        
        return copy;
    }
};