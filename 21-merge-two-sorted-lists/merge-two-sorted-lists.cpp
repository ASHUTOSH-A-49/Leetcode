
//   Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ml = new ListNode();
        ListNode * ptr= nullptr;
        while(list1 && list2){
            if(list1->val<=list2->val){
                if(!ptr) {
                    ptr = new ListNode(list1->val);
                    ml->next = ptr;
                }else{
                    ptr->next = new ListNode(list1->val);
                    ptr = ptr->next;
                }
                list1 = list1->next;
            }else{
                if(!ptr) {
                    
                    ptr = new ListNode(list2->val);
                    ml->next = ptr;
                }else{
                    ptr->next = new ListNode(list2->val);
                    ptr = ptr->next;
                }
                list2 = list2->next;
            }
        }

        while(list1){
            if(!ptr) {
                    
                    ptr = new ListNode(list1->val);
                    ml->next = ptr;
                }else{
                    ptr->next = new ListNode(list1->val);
                    ptr = ptr->next;
                }
                list1 = list1->next;
        }
        while(list2){
            if(!ptr) {
                    
                    ptr = new ListNode(list2->val);
                    ml->next = ptr;
                }else{
                    ptr->next = new ListNode(list2->val);
                    ptr = ptr->next;
                }
                list2 = list2->next;
        }
        return ml->next;
    }
};