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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(ListNode* l : lists){
            while(l){
                minHeap.push(l->val);
                l = l->next;
            }
        }
        if(minHeap.empty()) return nullptr;
        ListNode* root = new ListNode(minHeap.top());
        ListNode* dummy = root;
        minHeap.pop();
        while(!minHeap.empty()){
            ListNode* node = new ListNode(minHeap.top()) ;
            minHeap.pop();
            dummy->next = node;
            dummy = node;
        }
        return root;
    }
};