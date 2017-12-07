/* 
 * Problem: 2. Add Two Numbers[medium]
 * Source : https://leetcode.com/problems/add-two-numbers/description/
 * Solver : Baur Krykpayev
 * Date   : 12/07/2017
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* root = new ListNode(0);
        ListNode* cur = root;
        int carry = 0;
        
        while(l1 || l2 || carry)
        {
            int sum = 0;
            if (l1 && l2)
            {
                sum = l1->val + l2->val + carry;
                carry = sum/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                sum = l1->val + carry;
                carry = sum/10;
                l1 = l1->next;
            }
            else if (l2)
            {
                sum = l2->val + carry;
                carry = sum/10;
                l2 = l2->next;
            }
            else
            {
                sum = carry;
                carry = 0;
            }

            cur->next = new ListNode(sum%10);
            cur = cur->next;
        }
        
        return root->next;
    }
};