class Solution {
public:

    // Time: O(N * M)
    // Space: O(N * M)
    void setZeroes(vector<vector<int>>& matrix) {
        int row_cnt = matrix.size();
        int col_cnt = matrix[0].size();

        vector<bool> marked_row(row_cnt, false);
        vector<bool> marked_col(col_cnt, false);

        for (int i = 0; i < row_cnt; i++) {
            for (int j = 0; j < col_cnt; j++) {
                if (matrix[i][j] == 0) {
                    marked_row[i] = true;
                    marked_col[j] = true;
                }
            }
        }

        for (int i = 0; i < row_cnt; i++) {
            for (int j = 0; j < col_cnt; j++) {
                if (marked_row[i] || marked_col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};