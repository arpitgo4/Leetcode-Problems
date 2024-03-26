class Solution {
public:
    
    // Time: O(N)
    // Space: O(N)
    
    vector<int> dp;
    
    int dfs(int i, vector<int>& A, int N) {
        if (i >= N)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        return dp[i] = A[i] + min(
            dfs(i+1, A, N),
            dfs(i+2, A, N)
        );
    }
    
    int minCostClimbingStairs(vector<int>& A) {
        int N = A.size();
        dp.assign(N, -1);
        
        return min(dfs(0, A, N), dfs(1, A, N));
    }
};