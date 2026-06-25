class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize !=0) return false;
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i:hand) minH.push(i);

        while(!minH.empty()){
            vector<int> temp;
            int prev = minH.top();
            minH.pop();
            int k = groupSize-1;
            while(k>0){
                if(minH.empty()) return false;
                if(prev==minH.top()){
                    temp.push_back(minH.top());
                    minH.pop();
                    
                }else{
                    if(minH.top()==prev+1){
                        k--;
                        prev = minH.top();
                        minH.pop();
                    }else{
                        return false;
                    }
                }
            }
            for(int i:temp){
                minH.push(i);
            }
        }
        return true;
    }
};