class Solution {
public:

    // don't think we can use DP here. difficult to memoize the wheels represenstation (vector of 4 ints with values ranging [0,9])
        
    // brute-force backtracking algorithm should do
    // each transition is equally likely to happen, so we can consider the weight of each edge as 1,
    // because we want to find the minimum number of moves, BFS can be used

    // state: (vector<int>& lock)
    // transitions from each state,
    // 1. turn any wheel to right (4 wheels)
    // 2. turn any wheel to left (4 wheels)
    
    // Time: O(1e4)
    // Space: O(1e4)
    
    unordered_set<string> dict;
    unordered_map<string,int> vis, dist;
    
    int openLock(vector<string>& deadends, string target) {
        for (string& s : deadends)
            dict.insert(s);
        
        string src = "0000";
        return bfs(src, target);
    }
    
    int bfs(string& src, string& dest) {
        queue<string> q({ src });
        dist[src] = 0;
        vis[src] = 1;
        
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            
            if (vis[u] == 2 || dict.find(u) != dict.end())
                continue;
            vis[u] = 2;
            
            if (u == dest)
                return dist[u];
            
            for (int i = 0; i < 4; i++) {
                string v = u;
                int next = ((v[i]-'0')+1) % 10;
                v[i] = ('0'+next); 
                
                if (vis.find(v) == vis.end()) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    vis[v] = 1;
                }
                
                v = u;
                next = (v[i]-'0')-1;
                if (next < 0)
                    next = 9;
                
                v[i] = ('0'+next);
                
                if (vis.find(v) == vis.end()) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    vis[v] = 1;
                }
            }
        }
        
        return -1;
    }
};