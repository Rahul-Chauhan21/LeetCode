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
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        /*
        //O(n) time | O(n) space
        stack<ListNode*> nodes;
        ListNode* i = head;
        while(i){
            nodes.push(i);
            i = i->next;
        }

        if(nodes.empty()){
            return true;
        }
        i = head;
        while(!nodes.empty()){
            if(i->val != nodes.top()->val){
                return false;
            }
            i = i ->next;
            nodes.pop();
        }
        return true;
    }*/
        //O(n) time | O(1) space
        bool reveal = true;
        ListNode* fast = head;
        ListNode* slow = head;

            while(fast&& fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }

            slow = reverseList(slow);
            ListNode* middle = slow;
            while(slow){
                if(slow->val != head->val){
                    reveal = false;
                    break;
                }
                slow = slow->next;
                head = head->next;
            }
        reverseList(middle);
        return reveal;

    }
};
