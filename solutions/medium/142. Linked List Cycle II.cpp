/* 
 * Problem: 142. Linked List Cycle II[medium]
 * Source : https://leetcode.com/problems/linked-list-cycle-ii/description/
 * Solver : Baur Krykpayev
 * Date   : 12/09/2017
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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *cur = head;
        set<ListNode*> hash;
        
        while (cur)
        {
            if (hash.find(cur) == hash.end())
            {
                hash.insert(cur);
            }
            else
            {
                return cur;
            }
            
            cur = cur->next;
        }
            
        return NULL;
    }
};