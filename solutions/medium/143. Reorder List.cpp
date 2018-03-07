/* 
 * Problem: 143. Reorder List[medium]
 * Source : https://leetcode.com/problems/reorder-list/description/
 * Solver : Baur Krykpayev
 * Date   : 3/6/2018
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
    void reorderList(ListNode* head) 
    {
        if (!head || !head->next)
        {
            return;
        } 
        
        ListNode* cur = head;
        ListNode* back = head;
        
        while (back->next && back->next->next)
        {
            cur = cur->next;
            back = back->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        cur = head;
        back = prev;
        
        ListNode* cur_next = NULL;
        ListNode* back_next = NULL;
            
        while (cur)
        {
            cur_next = cur->next;
            cur->next = back;
            
            back_next = back->next;
            back->next = cur_next;
            
            cur = cur_next;
            back =  back_next;
        }
    }
};