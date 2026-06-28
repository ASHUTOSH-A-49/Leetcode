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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* ptr1 = head,*ptr2= head->next,*temp = ptr2;
        if(!ptr2 ||!ptr2->next) return head;
        while(ptr2 && ptr2->next){
            
            ptr1->next = ptr2->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr1->next = temp;
        return head;
    }
};