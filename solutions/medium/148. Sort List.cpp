/* 
 * Problem: 148. Sort List [medium]
 * Source : https://leetcode.com/problems/sort-list/description/
 * Solver : Baur Krykpayev
 * Date   : 5/19/2018
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
    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next){return head;}
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }

private:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;

        while (a && b)
        {
            if (a->val < b->val)
            {
                cur->next = a;    
                a = a->next;
            }
            else
            {
                cur->next = b;    
                b = b->next;
            }
            cur=cur->next;
        }
        if (a){cur->next = a;}
        if (b){cur->next = b;}
        
        return pre->next;
    }
};