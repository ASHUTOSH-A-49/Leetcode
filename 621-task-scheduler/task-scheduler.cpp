
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int> hash;
        for(int i :tasks) hash[i]++;
        priority_queue<int> pq;
        for(auto p:hash){
            pq.push(p.second);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle = n + 1; 
            int tasks_processed = 0;
            for(int i = 0; i < cycle; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    tasks_processed++;
                }
            }
            for(int freq : temp){
                if(freq > 0) pq.push(freq);
            }
            time += pq.empty() ? tasks_processed : cycle;
        }
        return time;
    }
};