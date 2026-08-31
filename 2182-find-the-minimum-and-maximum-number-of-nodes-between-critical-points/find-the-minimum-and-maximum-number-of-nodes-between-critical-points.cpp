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
        
        vector<int> arr;
        ListNode* ptr = head;
        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = arr.size();
        int maxi = 0,mini = n;
        vector<int> cp;
        for(int i = 1;i<n-1;i++){
            if((arr[i]>arr[i+1] && arr[i]>arr[i-1]) || 
                (arr[i]<arr[i+1] && arr[i] < arr[i-1])){
                    cp.push_back(i);
                }
        }
        if(cp.size()<=1) return {-1,-1};
        int m = cp.size();
        // for(int i:cp) cout<<i<<" ";
        for(int i = 0;i<m-1;i++){
            mini = min(mini,cp[i+1]-cp[i]);
        }
        maxi = cp[m-1]-cp[0];
        return {mini,maxi};
        
    }
};