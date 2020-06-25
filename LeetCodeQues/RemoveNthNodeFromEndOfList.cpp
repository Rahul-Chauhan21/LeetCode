/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //O(n) time | O(1) space
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        while(n--){
            fastPointer = fastPointer -> next;
        }
        if(fastPointer == NULL){
            return head->next;
        }

        while(fastPointer->next != NULL){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
        slowPointer->next = slowPointer->next->next;
        return head;
    }
};
