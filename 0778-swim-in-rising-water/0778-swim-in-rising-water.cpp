class Solution {
public:
    
    // Time: O(N * M * log(3e3))
    // Space: O(N * M)

    vector<vector<int>> vis;
    
    vector<pair<int,int>> moves{
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };
    
    bool can_reach(int i, int j, int time, vector<vector<int>>& G, int N, int M) {
        if (i == N-1 && j == M-1)
            return true;
        if (G[i][j] > time)
            return false;
        
        vis[i][j] = 1;
        
        bool reachable = false;
        for (pair<int,int>& move : moves) {
            int n_i = i + move.first, n_j = j + move.second;
            if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M && vis[n_i][n_j] == 0 && G[n_i][n_j] <= time)
                reachable = reachable || can_reach(n_i, n_j, time, G, N, M);
        }
        
        vis[i][j] = 2;
        
        return reachable;
    }
    
    int swimInWater(vector<vector<int>>& G) {
        int N = G.size();
        int M = G[0].size();
        
        int l = 0, h = 3e3;
        while (l <= h) {
            vis.assign(N, vector<int>(M, 0));
            
            int m = (h-l)/2 + l;
            if (can_reach(0, 0, m, G, N, M))
                h = m-1;
            else l = m+1;
        }
        
        return l;
    }
};