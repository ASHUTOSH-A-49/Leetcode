class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
if (n <= 1) {
    return 0;
}
unordered_map<int, vector<int>> graph;
for (int i = 0; i < n; i++) {
    graph[arr[i]].push_back(i);
}
vector<int> curs;
curs.push_back(0);
vector<bool> visited(n, false);
visited[0] = true; 
int step = 0;
while (!curs.empty()) {
    vector<int> nex;
    for (int node : curs) {
        if (node == n - 1) {
            return step;
        }
        for (int child : graph[arr[node]]) {
            if (!visited[child]) {
                visited[child] = true;
                nex.push_back(child);
            }
        }
        graph[arr[node]].clear();
        if (node + 1 < n && !visited[node + 1]) {
            visited[node + 1] = true;
            nex.push_back(node + 1);
        }
        if (node - 1 >= 0 && !visited[node - 1]) {
            visited[node - 1] = true;
            nex.push_back(node - 1);
        }
    }
    curs = nex;
    step++;
}
return -1;
    }
};