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
        // better approach (traversing and find idx and store directly into cp  vec)
        vector<int> cp;
        int maxi = 0,mini = 1e5,idx = 0,prev= 0;
        ListNode* ptr = head;
        while(ptr){
            if(idx==0 || ptr->next==nullptr) {
                prev = ptr->val;
                
                
            }
            else if((ptr->val > prev && ptr->val > ptr->next->val) ||
                (ptr->val < prev && ptr->val < ptr->next->val)) {
                    // cout<<prev<<" "<<ptr->val<<" "<<ptr->next->val<<endl;
                    cp.push_back(idx);
                    prev = ptr->val;
                    
                }
            prev = ptr->val;
            ptr= ptr->next;
            idx++;
            
            
        }
        if(cp.size() <=1) return {-1,-1};
        int m = cp.size();
        maxi = cp[m-1]-cp[0];
        // for(int i:cp) cout<<i<<" ";
        for(int i =0;i<m-1;i++){
            mini = min(mini,cp[i+1]-cp[i]);
        }
        return {mini,maxi};
        
        
    }
};