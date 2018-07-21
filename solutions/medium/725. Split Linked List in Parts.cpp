/* 
 * Problem: 725. Split Linked List in Parts [medium]
 * Source : https://leetcode.com/problems/split-linked-list-in-parts/description/
 * Solver : Baur Krykpayev
 * Date   : 07/20/2018
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) 
    {
        vector<ListNode*> ans;
        int total = 0;
        ListNode* cur = root;
        while (cur)
        {
            total++;
            cur = cur->next;
        }
        
        int cnt = total/k;
        int rem = total%k;
        cur = root;
        ListNode* prev = NULL;
        
        for (int i = 0; i < k; i++)
        {
            ans.push_back(cur);
            prev = NULL;
            
            int x = cnt;
            
            while (x)
            {
                prev = cur; x--;
                cur = (cur) ? cur->next : NULL;
            }
            
            if (rem)
            {
                prev = cur; rem--;
                cur = (cur) ? cur->next : NULL;
            }
            
            if (prev) {prev->next = NULL;}
        }

        return ans;
    }
};