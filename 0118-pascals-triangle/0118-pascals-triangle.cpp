class Solution {
public:

    // Time: O(N * K)
    // Space: O(N * K)

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<vector<int>> dp(numRows+1, vector<int>(numRows+1, -1));
        for (int total = 0; total < numRows; total++) {
            result.emplace_back(vector<int>());
            for (int choose = 0; choose <= total; choose++) {
                int cnt = countCombinations(total, choose, dp);
                result.back().emplace_back(cnt);
            }
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