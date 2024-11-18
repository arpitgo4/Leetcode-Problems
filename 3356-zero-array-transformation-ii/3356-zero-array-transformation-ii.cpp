class Solution {
public:
    
    // Time: O(NlogK)
    // Space: O(N)
    
    // Binary Search with Difference array
    
    bool check(int k, vector<int> A, vector<vector<int>>& Q) {
        int N = A.size();
        
        vector<int> D(N, -1);
        D[0] = A[0];
        for (int i = 1; i < N; i++)
            D[i] = A[i] - A[i-1];
        
        for (int i = 0; i < k; i++) {
            auto& v = Q[i];
            int l = v[0], r = v[1], val = v[2];
            D[l] -= val;
            if (r+1 < N)
                D[r+1] += val;
        }
        
        A[0] = D[0];
        bool canBe = A[0] <= 0;
        for (int i = 1; i < N; i++) {
            A[i] = A[i-1] + D[i];
            if (A[i] > 0)
                canBe = false;
        }
        
        return canBe;
    }
    
    int minZeroArray(vector<int>& A, vector<vector<int>>& Q) {
        int N = A.size();
        int K = Q.size();
        
        int l = 0, h = K;
        while (l <= h) {
            int m = (h-l)/2 + l;
            if (check(m, A, Q))
                h = m-1;
            else l = m+1;
        }
        
        return (l > K ? -1 : l);
    }
};