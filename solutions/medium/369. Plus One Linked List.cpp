/* 
 * Problem: 369. Plus One Linked List [medium]
 * Source : https://leetcode.com/problems/plus-one-linked-list/description/
 * Solver : Baur Krykpayev
 * Date   : 5/30/2018
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
    ListNode* plusOne(ListNode* head) 
    {
        if (!head) {return head;}
        ListNode* cur = head;
        stack<ListNode*> s;
        
        while(cur)
        {
            s.push(cur);
            cur = cur->next;
        }
        
        int carry = 1;
        while(!s.empty() && carry)
        {
            cur = s.top(); s.pop();
            int temp = cur->val+1;
            cur->val = temp%10;
            carry = temp/10;
        }
        
        if (carry)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
            
        return head;
    }
};