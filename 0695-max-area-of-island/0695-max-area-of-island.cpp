class Solution {
public:
    
    // Time: O(N * M * ⍺(N * M))
    // Space: O(N * M)
    
    vector<int> P, S;
    
    int root(int x) {
        if (P[x] != x)
            P[x] = root(P[x]);
        
        return P[x];
    }
    
    void union_set(int x, int y) {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y)
            return;
        
        if (S[root_x] < S[root_y])
            swap(root_x, root_y);
        
        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    }
    
    int get_idx(int i, int j, int M) {
        return i * M + j;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& G) {
        int N = G.size();
        int M = G[0].size();
        
        P.assign(N * M, -1);
        S.assign(N * M, -1);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                P[get_idx(i, j, M)] = get_idx(i, j, M);
                S[get_idx(i, j, M)] = G[i][j];
            }
            
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (G[i][j] == 1) {
                    if (i > 0 && G[i-1][j] == 1)
                        union_set(get_idx(i, j, M), get_idx(i-1, j, M));
                    if (j > 0 && G[i][j-1] == 1)
                        union_set(get_idx(i, j, M), get_idx(i, j-1, M));    
                }
            }
        
        int max_area = 0;
        for (int i = 0; i < N * M; i++)
            max_area = max(max_area, S[i]);
        
        return max_area;
    }
};