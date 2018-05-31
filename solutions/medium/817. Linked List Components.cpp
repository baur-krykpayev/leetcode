/* 
 * Problem: 817. Linked List Components [medium]
 * Source : https://leetcode.com/problems/linked-list-components/description/
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
    int numComponents(ListNode* head, vector<int>& G) 
    {
        unordered_set<int> s(G.begin(), G.end());
        ListNode* cur = head;
        int cnt = 0;
        
        while (cur)
        {
            int found = false;
            while(cur && s.count(cur->val))
            {
                found = true;
                cur = cur->next;
            }
            if (found){cnt++;}
            if (cur){cur = cur->next;}
        }
        
        return cnt;
    }
};