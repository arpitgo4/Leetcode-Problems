class Solution {
public:
    
    // Time: O(N*M * ⍺(N*M))
    // Space: O(N*M)
    
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
    
    int countServers(vector<vector<int>>& G) {
        int N = G.size();
        int M = G[0].size();
        
        P.assign(N*M, -1);
        S.assign(N*M, 1);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                int idx = i * M + j;
                P[idx] = idx;
            }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (G[i][j] == 1) {
                    int idx = i * M + j;
                    
//                     if (root(idx) != idx)                     // already been included in the disjoint set. no need to check neighbours
//                         continue;
                    
                    int jj = j+1;
                    while (jj < M) {
                        if (G[i][jj] == 1)
                            union_set(i*M+jj, idx);
                        jj++;
                    }
                    
                    int ii = i+1;
                    while (ii < N) {
                        if (G[ii][j] == 1)
                            union_set(ii*M+j, idx);
                        ii++;
                    }
                }
            }
        
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                int idx = i * M + j;
                if (S[idx] > 1)
                    count += S[idx];
            }
        
        return count;
    }
};