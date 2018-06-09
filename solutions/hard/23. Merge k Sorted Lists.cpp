/* 
 * Problem: 23. Merge k Sorted Lists [hard]
 * Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
 * Solver : Baur Krykpayev
 * Date   : 6/9/2018
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* pre = new ListNode(0);
        
        if (!lists.size()) {return NULL;}
        pre->next = lists[0];
        
        for (int i = 1; i < lists.size(); i++)
        {
            pre->next = mergeLists(pre->next, lists[i]);    
        }
        
        return pre->next;
    }
    
private:
    ListNode* mergeLists(ListNode* a, ListNode* b)
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
            cur = cur->next;
        }
        
        if (a) {cur->next = a;}
        if (b) {cur->next = b;}
        
        return pre->next;
    }
};