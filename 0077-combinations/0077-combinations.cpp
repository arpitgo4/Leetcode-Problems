class Solution {
public:

    // Time: O(N^K)
    // Space: O(K)

    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        comb(1, n, k, *new vector<int>());
        return result;
    }

    void comb(int i, int N, int K, vector<int>& acc) {
        if (acc.size() == K) {
            result.push_back(acc);
            return;
        }
        if (i > N)
            return;

        acc.push_back(i);
        comb(i+1, N, K, acc);
        acc.pop_back();

        comb(i+1, N, K, acc);
    }
};