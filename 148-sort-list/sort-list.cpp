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

class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    // approach 1 - priority queue with custom comparator
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        priority_queue<ListNode*,vector<ListNode*>, compare> minH;
        while(head){
            minH.push(head);
            head = head->next;
        }
        ListNode* newHead = minH.top();
        minH.pop();
        ListNode* tmp = newHead;
        while(minH.size()>0){
            ListNode* nxt = minH.top();minH.pop();
            tmp->next = nxt;
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return newHead;
    }
};