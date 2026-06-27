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

// void printLL(ListNode* head){
//     while(head){
//         cout<<head->val<<" ";
//         head = head->next;
//     }
// }

ListNode* getMid(ListNode* head){
    ListNode* slow  = head,* fast = head;
        while(fast){
            if(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }else break;  
        }
    return slow;
}


ListNode* revLL(ListNode* head){
    if(!head) return head;
        ListNode * prev = nullptr, *curr = head, * next = curr->next;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
}

//APPROACH -2 : rev one half of LL and compare with other (first get mid using slow and fast ptr)
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* mid = nullptr,* nxt = nullptr;
        mid = getMid(head);
        nxt = revLL(mid->next);
        mid->next = nxt;
        mid = mid->next;
        while(mid){
            if(head->val !=mid->val) return false;
            head = head->next;mid = mid->next;
        }
        return true;
        
    }
};