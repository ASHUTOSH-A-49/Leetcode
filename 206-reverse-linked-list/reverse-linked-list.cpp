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
    // approach 1 create a ll and add at first always
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* tail = new ListNode(head->val);
        tail->next = nullptr;
        head= head->next;
        while(head){
            ListNode* tmp = new ListNode(head->val);
            tmp->next = tail;
            tail = tmp;
            head = head->next;
        }
        return tail;
    }
};