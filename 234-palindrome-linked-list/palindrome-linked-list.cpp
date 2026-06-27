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
ListNode* revLL(ListNode*head){
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
// void printLL(ListNode* head){
//     while(head){
//         cout<<head->val<<" ";
//         head = head->next;
//     }
// }

//APPROACH -1 : make new ll which is rev of original LL and compare - SC - O(N)
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* head2 = revLL(head);
        // printLL(head2);
        while(head && head2){
            if(head->val!=head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
        
    }
};