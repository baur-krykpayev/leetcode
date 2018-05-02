/* 
 * Problem: 203. Remove Linked List Elements [easy]
 * Source : https://leetcode.com/problems/remove-linked-list-elements/description/
 * Solver : Baur Krykpayev
 * Date   : 5/2/2018
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode prehead;
    prehead.next = head;
    struct ListNode* prev = &prehead, *cur = head;
    while (cur)
    {
        if (cur->val != val)
        {
            prev->next = cur;
            prev = prev->next;
        }
        cur = cur->next;
    }
    prev->next = cur;
    
    return prehead.next;
}