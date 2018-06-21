/* 
 * Problem: 82. Remove Duplicates from Sorted List II [medium]
 * Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 06/20/2018
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) {return head;}
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = pre;
        int val = 0;
    
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int val = cur->next->val;
                
                while (cur->next && cur->next->val == val)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;   
            }
        }
        
        return pre->next;
    }
};