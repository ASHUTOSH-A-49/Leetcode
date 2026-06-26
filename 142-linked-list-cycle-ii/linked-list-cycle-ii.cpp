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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;

        while(fast){
            if(fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast) return true;
            }else break;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head)) return nullptr;
        map<ListNode*,int> hash;
        ListNode* temp  = head;
        ListNode* ans = new ListNode(-1);
        while(true){
            hash[temp]++;
            if(hash[temp]>1) {
                ans = temp;
                break;
            }
            temp =temp->next;
        }
        return ans;

    }
};