/* 
 * Problem: 382. Linked List Random Node [medium]
 * Source : https://leetcode.com/problems/linked-list-random-node/description/
 * Solver : Baur Krykpayev
 * Date   : 5/31/2018
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        this->head = head;
        ListNode* cur = head;
        while (cur)
        {
            cnt++;
            cur = cur->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int ind = rand()%cnt;
        ListNode* cur = head;
        while (ind--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
private:
    int cnt = 0;
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */