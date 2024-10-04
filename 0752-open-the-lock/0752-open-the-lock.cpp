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
            string s = q.front();
            q.pop();
            
            int move = dist[s];
            if (vis[s] == 2 || dict.find(s) != dict.end())
                continue;
            vis[s] = 2;
            
            for (int i = 0; i < 4; i++) {
                string t = s;
                int next = ((t[i]-'0')+1) % 10;
                t[i] = ('0'+next);
                
                if (vis.find(t) == vis.end() && dict.find(t) == dict.end()) {
                    q.push(t);
                    dist[t] = move + 1;
                    vis[t] = 1;
                }
                
                if (t == dest)
                    return dist[t];
                
                t = s;
                next = (t[i]-'0')-1;
                if (next < 0)
                    next = 9;
                
                t[i] = ('0'+next);
                
                if (vis.find(t) == vis.end() && dict.find(t) == dict.end()) {
                    q.push(t);
                    dist[t] = move + 1;
                    vis[t] = 1;
                }
                
                if (t == dest)
                    return dist[t];
            }
        }
        
        return -1;
    }
};