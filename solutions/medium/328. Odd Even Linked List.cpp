/* 
 * Problem: 328. Odd Even Linked List[medium]
 * Source : https://leetcode.com/problems/odd-even-linked-list/description/
 * Solver : Baur Krykpayev
 * Date   : 11/22/2017
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) 
{
    if (!head || !head->next || !head->next->next)
    {
        return head;
    }
    
    struct ListNode* current = head;
    struct ListNode* even = current->next;
    struct ListNode* odd = even->next;
    
    while(odd)
    {
        even->next = odd->next;
        odd->next = current->next; 
        current->next = odd;
        
        current = odd;
        even = even->next;
        if (even)
        {
            odd = even->next;    
        }
        else
        {
            odd = NULL;
        }
    } 
    
    return head;
}