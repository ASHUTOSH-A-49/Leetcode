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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Optimal - No aux space used
        int maxi = 0,mini = 1e6,idx = 0,prev= 0,prevcp = -1,firstcp = -1;
        ListNode* ptr = head;
        while(ptr){
            if(idx==0 || ptr->next==nullptr) {
                prev = ptr->val;
                
            }
            else if((ptr->val > prev && ptr->val > ptr->next->val) ||
                (ptr->val < prev && ptr->val < ptr->next->val)) {
                    if(prevcp==-1){
                        firstcp = idx;
                        prevcp = idx;
                    }else{
                        mini = min(idx-prevcp,mini);
                        prevcp = idx;
                    }
                    
                }
            prev = ptr->val;
            ptr= ptr->next;
            idx++;
            
            
        }
        if(firstcp==-1 || firstcp==prevcp) return {-1,-1};
        maxi = prevcp-firstcp;
        return {mini,maxi};
        
        
    }
};