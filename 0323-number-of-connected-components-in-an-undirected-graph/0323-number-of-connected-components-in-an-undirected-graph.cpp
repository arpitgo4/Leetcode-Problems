class Solution {
public:
    
    // Time: O(⍺(N))
    // Space: O(N)
    
    vector<int> P, S;
    
    int root(int x) {
        if (P[x] != x)
            P[x] = root(P[x]);                                          // path-compression
        
        return P[x];
    }
    
    void union_set(int x, int y) {
        int root_x = root(x); 
        int root_y = root(y);
        if (root_x == root_y)
            return;
        
        if (S[root_x] < S[root_y])                                      // union by rank (size of tree)
            swap(root_x, root_y);
        
        P[root_y] = P[root_x];
        S[root_x] += S[root_y];
        S[root_y] = -1;
    }
    
    int countComponents(int V, vector<vector<int>>& edges) {
        P.assign(V, -1);
        S.assign(V, 1);
        for (int i = 0; i < V; i++)
            P[i] = i;
        
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1];
            if (root(u) != root(v))
                union_set(u, v);
        }
        
        int count = 0;
        for (int i = 0; i < V; i++)
            if (S[i] != -1)
                count++;
            
        return count;
    }
};