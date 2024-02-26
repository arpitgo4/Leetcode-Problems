class Solution {
public:

    // There are back-edges in the resulting graph. There can be more
    // efficient path taking a back-edge via a parent sub-problem for current
    // problem. Hence, DP can't be used
    
    // Dijkstra, can be used taking edge weights 0 & 1. Time: O(N * M * log(N * M))
    // 0-1 BFS is the most optimal solution for this. Time: O(N * M)

    // Time: O(N * M)
    // Space: O(N * M)

    typedef tuple<int,int,int> state;

    const int INF = INT_MAX;
    vector<vector<int>> dist, vis;

    const vector<pair<int,int>> moves = {
        { -1, 0 },                  // up
        { 1, 0 },                   // down
        { 0, -1 },                  // left
        { 0, 1 }                    // right
    };

    // 0-1 BFS
    void bfs(int src_i, int src_j, vector<vector<int>>& G, int M, int N) {
        deque<state> dq;

        dist[src_i][src_j] = 0;
        dq.push_front({ dist[src_i][src_j], src_i, src_j });

        while (!dq.empty()) {
            state s = dq.front();
            dq.pop_front();

            int i = get<1>(s), j = get<2>(s);
            if (vis[i][j] != 0)
                continue;
            vis[i][j] = 1;

            for (auto p : moves) {
                int n_i = i + p.first, n_j = j + p.second;
                if (n_i >= 0 && n_i < M && n_j >= 0 && n_j < N && dist[n_i][n_j] > dist[i][j] + G[i][j]) {
                    dist[n_i][n_j] = dist[i][j] + G[i][j];
                    if (G[i][j] == 0)
                        dq.push_front({ dist[n_i][n_j], n_i, n_j });
                    else dq.push_back({ dist[n_i][n_j], n_i, n_j });
                }
            }
        }
    }

    int minimumObstacles(vector<vector<int>>& G) {
        int M = G.size();
        int N = G[0].size();

        dist.assign(M, vector<int>(N, INF));
        vis.assign(M, vector<int>(N, 0));

        bfs(0, 0, G, M, N);

        return dist[M-1][N-1];
    }
};