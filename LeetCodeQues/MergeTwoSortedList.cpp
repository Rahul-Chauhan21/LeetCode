/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4


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
    //O(m + n) time | O(1) space
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* k = new ListNode(0);
        ListNode* iterator = k;
        while(l1 && l2){
            if(l1->val <= l2->val){
                iterator->next = l1;
                l1 = l1->next;
            }
            else{
                iterator->next = l2;
                l2 = l2->next;
            }
            iterator = iterator->next;
        }
        iterator->next = l1 ? l1 : l2;
        return k->next;
    }
};
