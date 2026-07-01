const int INF = INT_MAX;

class Solution {
public:

    // Time: O(N * M)
    // Space: O(N * M)
    int minPathSum(vector<vector<int>>& grid) {
        int row_cnt = grid.size();
        int col_cnt = grid[0].size();

        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, -1));

        return findMinPathSum(
            0,
            0,
            row_cnt,
            col_cnt,
            grid,
            dp
        );
    }

    int findMinPathSum(
        int curr_row,
        int curr_col,
        int row_cnt,
        int col_cnt,
        vector<vector<int>>& grid,
        vector<vector<int>>& dp
    ) {
        if (curr_row < 0 || curr_row == row_cnt ||
            curr_col < 0 || curr_col == col_cnt) {
            return INF;
        }

        if (curr_row == row_cnt-1 && curr_col == col_cnt-1) {
            return grid[curr_row][curr_col];
        }

        if (dp[curr_row][curr_col] != -1) {
            return dp[curr_row][curr_col];
        }

        int down_min_sum = findMinPathSum(
            curr_row + 1,
            curr_col,
            row_cnt,
            col_cnt,
            grid,
            dp
        );
        if (down_min_sum != INF) {
            down_min_sum += grid[curr_row][curr_col];
        }

        int right_min_sum = findMinPathSum(
            curr_row,
            curr_col + 1,
            row_cnt,
            col_cnt,
            grid,
            dp
        );
        if (right_min_sum != INF) {
            right_min_sum += grid[curr_row][curr_col];
        }

        return dp[curr_row][curr_col] = min(
            down_min_sum,
            right_min_sum
        );
    }
};