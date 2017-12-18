/* 
 * Problem: 24. Swap Nodes in Pairs[medium]
 * Source : https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Solver : Baur Krykpayev
 * Date   : 12/17/2017
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {  
        ListNode** mem = &head;
        ListNode* odd = *mem;
        ListNode* even = (odd) ? odd->next : NULL;
        
        while (odd && even)
        {
            odd->next = even->next;
            even->next = odd;
            *mem = even;
            mem = &(odd->next);
            odd = *mem;
            even = (odd) ? odd->next : NULL;
        }
        
        return head;
    }
};