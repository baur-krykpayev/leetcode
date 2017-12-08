/* 
 * Problem: 19. Remove Nth Node From End of List[medium]
 * Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * Solver : Baur Krykpayev
 * Date   : 12/08/2017
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* newHead = new ListNode(0);
        ListNode* slow = newHead;
        ListNode* fast = newHead;
        slow->next = head;
        
        for (int i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return newHead->next;
    }
};