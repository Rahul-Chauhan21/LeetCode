/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// The idea is to associate the original node with its copy node in a singly linked list. In this way,
// we don't need extra space to keep track of the new nodes.

class Solution {
public:
    //O(n) time | O(1) time
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* iterator = head;
        while(iterator){
            Node* nextNode = iterator->next;
            iterator->next = new Node(iterator->val);
            iterator->next->next = nextNode;
            iterator = nextNode;
        }
        iterator = head;
        while(iterator){
            if(iterator->random)
            iterator->next->random = iterator->random->next;
            iterator = iterator->next->next;
        }

        iterator = head;
        Node* copyHead = head->next;
        Node* copyIterator = copyHead;
        while(copyIterator->next){
            iterator->next = iterator->next->next;
            iterator = iterator->next;

            copyIterator->next = copyIterator->next->next;
            copyIterator = copyIterator->next;
        }
        iterator->next = iterator->next->next;
        return copyHead;
    }
};
