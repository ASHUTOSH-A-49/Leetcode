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
int cnt = 0;
void cntNodes(ListNode* head){
    cnt = 0;
    ListNode* tail = head;
    while(tail!=NULL){
        tail = tail->next;
        cnt++;
    }
     
}
ListNode* shiftK(ListNode* head,int k){
    k = k % cnt; 
    if(k==0) return head;
    ListNode* NewTail;
    ListNode* tail = head;
    for(int i = 0; i < (cnt - k - 1); i++){
        tail = tail->next;
    }
    NewTail = tail;
    ListNode* NewHead = tail->next;
    ListNode* temp = NewHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    NewTail->next = NULL;
    return NewHead;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        cntNodes(head);
        return shiftK(head,k);
    }
};