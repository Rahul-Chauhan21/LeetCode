/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseList(ListNode* first, ListNode* last){
        ListNode* prev = last;
        while(first != last){
            ListNode* temp = first->next;
            first->next = prev;
            prev = first;
            first = temp;
        }
        return prev;
    }
public:
    //O(n) time | O(n/k) space
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for(int i = 0; i < k; i++){
            if(!node){
                return head;
            }
            node = node -> next;
        }

        ListNode* newHead = reverseList(head, node);
        head->next = reverseKGroup(node, k);
        return newHead;
    }
};
