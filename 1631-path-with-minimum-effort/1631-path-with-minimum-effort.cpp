class Solution {
public:
    
    // Time: O(N * M * log(N * M))
    // Space: O(N * M)
    
    vector<pair<int,int>> moves{
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };
    
    vector<int> P, S, W;
    
    int get_idx(int i, int j, int M) {
        return i * M + j;
    }
    
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
        
        if (S[root_x] < S[root_y]) {
            swap(root_x, root_y);
            swap(x, y);
        }
        
        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    }
    
    int minimumEffortPath(vector<vector<int>>& G) {
        int N = G.size();
        int M = G[0].size();
        
        P.assign(N*M, -1);
        S.assign(N*M, 1);
        for (int i = 0; i < N*M; i++)
            P[i] = i;
        
        vector<tuple<int,int,int>> edges;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (auto& move : moves) {
                    int n_i = move.first + i, n_j = move.second + j;
                    if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M)
                        edges.push_back({ get_idx(i, j, M), get_idx(n_i, n_j, M), abs(G[i][j]-G[n_i][n_j]) });
                }
            }
        }
        
        sort(edges.begin(), edges.end(), [&](const auto& t1, const auto& t2) {
            return get<2>(t1) < get<2>(t2);
        });
        
        int src = get_idx(0, 0, M), dest = get_idx(N-1, M-1, M);
        int u, v, w;
        for (auto& edge : edges) {
            tie(u, v, w) = edge;
            if (root(u) != root(v)) {
                union_set(u, v);
            }
            
            if (root(src) == root(dest))
                return w;
        }
        
        return 0;
    }
};