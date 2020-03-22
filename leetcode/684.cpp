//https://leetcode-cn.com/problems/redundant-connection/
class Solution {
public:
    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    bool merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            return false;
        }
        parent[pa] = pb;
        return true;
    }
    void init() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (auto& edge: edges) {
            int a = edge[0];
            int b = edge[1];
            if (merge(a ,b) == false) {
                return {a, b};
            }
        }
        
        return {0, 0};
    }
    const static int N = 1024;
    int parent[N];
};
