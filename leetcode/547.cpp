class Solution {
public:
    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return find(parent[a]);
    }
    void merge(int a, int b) {
        int pa = find(a);
 
        int pb = find(b);
 
        parent[pa] = pb;
    }
    int findCircleNum(vector<vector<int>>& M) {

        int N = M.size();

        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (M[i][j] == 1) {
                    merge(i, j);
                }
            }
        }
        int r = 0;
        for (int i = 0; i < 202; ++i) {
            if (parent[i] == i) {
                r++;
            }
        }
        return r;
    }
    int parent[202];
};
