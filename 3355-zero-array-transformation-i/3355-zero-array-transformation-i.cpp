class Solution {
public:

    // Time: O(N)
    // Space: O(N)

    bool isZeroArray(vector<int>& A, vector<vector<int>>& Q) {
        int N = A.size();

        vector<int> diff(N, 0);
        diff[0] = A[0];
        for (int i = 1; i < N; i++)
            diff[i] = A[i] - A[i-1];

        for (auto& v : Q) {
            int l = v[0];
            int r = v[1];
            diff[l] -= 1;
            if (r < N-1)
                diff[r+1] += 1;
        }

        A[0] = diff[0];
        bool canBe = A[0] <= 0;
        for (int i = 1; i < N; i++) {
            A[i] = A[i-1] + diff[i];
            if (A[i] > 0)
                canBe = false;
        }

        return canBe;
    }
};