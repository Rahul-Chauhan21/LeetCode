/*
1 2 3
4 5
o/p: null

1 2 3 4 5
7 8 9 3 4 5
o/p: 3
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        //O(m + n) time | O(m) or o(n) space
        unordered_set<ListNode*> nodes;
            while(headA != NULL){
                nodes.insert(headA);
                headA = headA->next;
            }
            if(nodes.empty()){
                return NULL;
            }
            while(headB != NULL){
                if(nodes.find(headB) != nodes.end()){
                    return headB;
                }
                headB = headB -> next;
            }
        return NULL;*/


        //Two pointer approach
        //O(m + n) time | O(1) space
        ListNode *pa = headA, *pb = headB;
        while(pa != pb){
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;
        }
        return pa;
    }
};
