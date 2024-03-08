class Solution {
public:
    
    // Time: O(N * M * log(N * M))
    // Space: O(N * M)
    
    // weight for an edge can defined as, max(W[i,j], Route[i,j])
    
    #define INF INT_MAX
    
    typedef tuple<int,int,int> state;
    
    vector<vector<int>> dist, vis;
    
    vector<pair<int,int>> moves{
        { -1, 0 },
        { 1, 0 },
        { 0, -1 },
        { 0, 1 },
    };
    
    void dijkstra(int src_i, int src_j, vector<vector<int>>& G, int N, int M) {
        auto comp = [&](const state& t1, const state& t2) {
            return get<0>(t1) > get<0>(t2);
        };
        priority_queue<state, vector<state>, decltype(comp)> pq(comp);              // min-heap
        
        dist[src_i][src_j] = 0;
        pq.push({ dist[src_i][src_j], src_i, src_j });
        
        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();
            
            int d, i, j;
            tie(d, i, j) = s;
            
            if (vis[i][j] != 0)
                continue;
            vis[i][j] = 1;
            
            for (auto& move : moves) {
                int n_i = move.first + i, n_j = move.second + j;
                if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
                    if (dist[n_i][n_j] > max(dist[i][j], abs(G[n_i][n_j]-G[i][j]))) {
                        dist[n_i][n_j] = max(dist[i][j], abs(G[n_i][n_j]-G[i][j]));
                        pq.push({ dist[n_i][n_j], n_i, n_j });
                    }
                }
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& G) {
        int N = G.size();
        int M = G[0].size();
        
        dist.assign(N, vector<int>(M, INF));
        vis.assign(N, vector<int>(M, 0));
        
        dijkstra(0, 0, G, N, M);
        
        return dist[N-1][M-1];
    }
};