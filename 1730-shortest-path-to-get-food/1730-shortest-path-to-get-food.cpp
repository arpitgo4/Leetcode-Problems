class Solution {
public:

    // Time: O(N * M)
    // Space: O(N * M)

    // use BFS

    typedef tuple<int,int,int> state;

    vector<vector<int>> vis;

    const vector<pair<int,int>> moves{
        { 1, 0 },
        { -1, 0 },
        { 0, -1 },
        { 0, 1 },
    };

    int bfs(int src_i, int src_j, vector<vector<char>>& G, int N, int M) {
        queue<state> q;

        q.push({ src_i, src_j, 0 });

        while (!q.empty()) {
            state s = q.front();
            q.pop();

            int i, j, dist;
            tie(i,j,dist) = s;
            if (vis[i][j] != 0)
                continue;
            vis[i][j] = 1;

            if (G[i][j] == '#')
                return dist;

            for (auto& move : moves) {
                int n_i = i + move.first, n_j = j + move.second;
                if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M && G[n_i][n_j] != 'X') {
                    q.push({ n_i, n_j, dist + 1 });
                }
            }
        }

        return -1;
    }

    int getFood(vector<vector<char>>& G) {
        int N = G.size();
        int M = G[0].size();

        vis.assign(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (G[i][j] == '*')
                    return bfs(i, j, G, N, M);

        return -1;
    }
};