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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> hash;
        ListNode* ans = nullptr;
        while(headA){
            hash[headA]++;
            headA = headA->next;
        }
        while(headB){
            hash[headB]++;
            if(hash[headB]>1) {
                return headB;
            }
            headB = headB->next;
        }
        return ans;
    }
};