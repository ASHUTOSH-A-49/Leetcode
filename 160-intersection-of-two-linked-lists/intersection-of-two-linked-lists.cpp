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
//count nodes  and then start from same length;
    int cntNodes(ListNode * head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        int n1 = cntNodes(headA),n2 = cntNodes(headB);
        while(n1>n2){
            n1--;
            headA = headA->next;
        }
        while(n2>n1){
            n2--;
            headB = headB->next;
        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;headB = headB->next;
        }
        return nullptr;
    }
};