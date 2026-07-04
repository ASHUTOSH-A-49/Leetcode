/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//APPROACH 2: slow and fast 2 collision approach
    ListNode* hasCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;

        while(fast){
            if(fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast) return fast;
            }else break;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = hasCycle(head);
        if(!fast) return nullptr;
        //take one of pointer to head and move both pointer 1 step each
        ListNode* slow  = head;
        //2nd collision will always be at head
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }
};