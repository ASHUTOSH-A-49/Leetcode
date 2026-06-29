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
    // approach 2-array then sort or set  TC - O(NlogN), SC-O(N);
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode*tmp1 = head,*tmp2 = head;
        while(tmp1){
            arr.push_back(tmp1->val);
            tmp1= tmp1->next;
        }
        sort(arr.begin(),arr.end());
        int i = 0;
        while(tmp2){
            tmp2->val = arr[i++];
            tmp2 = tmp2->next;
        }
        return head;
    }
};