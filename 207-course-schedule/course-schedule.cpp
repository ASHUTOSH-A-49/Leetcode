class Solution {
public:
bool DFS(vector<vector<int>> &mat, vector<int> &visited, int start) {
        // State 1 means currently visiting (cycle detected)
        visited[start] = 1; 
        for (int i : mat[start]) {
            if (visited[i] == 1) return false;
            if (visited[i] == 0) {
                if (!DFS(mat, visited, i)) return false;
            }
        }
        // State 2 means fully processed (safe node)
        visited[start] = 2; 
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for (auto v : prerequisites) {
            G[v[0]].push_back(v[1]);
        }
        // 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> visited(numCourses, 0); 
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!DFS(G, visited, i)) return false;
            }
        }
        return true;
    }
};