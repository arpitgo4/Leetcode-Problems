class Solution {
public:

    // Time: O(N * M)
    // Space: O(N * M)
    int uniquePaths(int row_cnt, int col_cnt) {
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, -1));

        return countUniquePaths(
            0, 
            0, 
            row_cnt, 
            col_cnt,
            dp
        );
    }

    int countUniquePaths(
        int curr_row,
        int curr_col, 
        int row_cnt,
        int col_cnt,
        vector<vector<int>>& dp
    ) {
        if (
            curr_row < 0 || 
            curr_row == row_cnt || 
            curr_col < 0 ||
            curr_col == col_cnt) {
            return 0;
        }

        if (curr_row == row_cnt-1 && curr_col == col_cnt-1) {
            return 1;
        }

        if (dp[curr_row][curr_col] != -1) {
            return dp[curr_row][curr_col];
        }

        int right_cnt = countUniquePaths(
            curr_row,
            curr_col + 1,
            row_cnt,
            col_cnt,
            dp
        );

        int down_cnt = countUniquePaths(
            curr_row + 1,
            curr_col,
            row_cnt,
            col_cnt,
            dp
        );

        return dp[curr_row][curr_col] = right_cnt + down_cnt;
    }
};