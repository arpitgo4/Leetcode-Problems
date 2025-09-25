class Solution {
public:

    // Time: O(N * K)
    // Space: O(N * K)

    vector<int> getRow(int rowIndex) {
        vector<int> result;

        vector<vector<int>> dp(rowIndex+1, vector<int>(rowIndex+1, -1));
        for (int i = 0; i <= rowIndex; i++) {
            int cnt = countCombinations(rowIndex, i, dp);
            result.emplace_back(cnt);
        }

        return result;
    }

    int countCombinations(int total, int choose, vector<vector<int>>& dp) {
        if (choose == 0) {
            return 1;
        }
        if (total == 0) {
            return 0;
        }
        if (dp[total][choose] != -1) {
            return dp[total][choose];
        }

        int include_cnt = countCombinations(total - 1, choose - 1, dp);
        int exclude_cnt = countCombinations(total - 1, choose, dp);

        return dp[total][choose] = include_cnt + exclude_cnt;
    }
};