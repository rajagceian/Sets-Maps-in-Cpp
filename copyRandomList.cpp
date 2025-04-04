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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*,Node*>mp;  // {node of original ll,node of copied ll}
        Node* copied = new Node(-1);
        Node* newHead = copied;
        Node* curr = head;
        while(curr){
            newHead->next = new Node(curr->val);
            newHead=newHead->next;
            mp[curr]=newHead;
            curr=curr->next;
        }
        copied=copied->next; //head of copied LL
        for(auto &pair : mp){
            Node* a = pair.first; // node of original LL
            Node* b = pair.second; // node of copied LL
            b->random = mp[a->random];
        }
        return copied;
    }
};
