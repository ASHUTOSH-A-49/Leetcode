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

 class compare{
    public:
    bool operator()(ListNode*a, ListNode*b){
        return a->val>b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,compare> minH;
        for(ListNode* l : lists){
           if (l!=nullptr) minH.push(l);
        }
        if(minH.empty()) return nullptr;
        ListNode* root = nullptr;
        ListNode* prev = nullptr;
        while(!minH.empty()){
            ListNode* tmp = minH.top();
            if(!root) root = tmp;
            if(prev) prev->next = tmp;
            prev = tmp;
            minH.pop();
            if(tmp->next){
                ListNode * nxt = tmp->next;
                minH.push(nxt);
            }
            
        }
        return root;
    }
};