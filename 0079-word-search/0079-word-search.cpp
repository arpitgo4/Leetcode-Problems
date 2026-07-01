class Solution {
public:

    // Time: O((N * M)!)
    // Space: O(N * M)
    vector<pair<int,int>> moves {
        { -1, 0 },          // up
        { 1, 0 },           // down
        { 0, -1 },          // left
        { 0, 1 }            // right
    };

    bool exist(vector<vector<char>>& board, string word) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();

        vector<vector<int>> visited(row_cnt, vector<int>(col_cnt, 0));

        bool does_word_exists = false;
        for (int i = 0; i < row_cnt; i++) {
            for (int j = 0; j < col_cnt; j++) {
                bool exists = wordExists(
                    i, 
                    j,
                    0,
                    row_cnt, 
                    col_cnt, 
                    board, 
                    word,
                    visited
                );

                does_word_exists = does_word_exists || exists;
                if (does_word_exists) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordExists(
        int curr_row,
        int curr_col,
        int word_idx,
        int row_cnt,
        int col_cnt,
        vector<vector<char>>& board,
        string& word,
        vector<vector<int>>& visited
    ) {
        if (word_idx == word.length()) {
            return true;
        }

        if (
            curr_row < 0 || curr_row == row_cnt ||
            curr_col < 0 || curr_col == col_cnt ||
            visited[curr_row][curr_col] == 1
        ) {
            return false;
        }

        if (word[word_idx] != board[curr_row][curr_col]) {
            return false;
        }

        visited[curr_row][curr_col] = 1;

        bool does_exist = false;
        for (auto& move : moves) {
            int next_row = curr_row + move.first;
            int next_col = curr_col + move.second;
            bool exists = wordExists(
                next_row,
                next_col,
                word_idx + 1,
                row_cnt,
                col_cnt,
                board,
                word,
                visited
            );

            does_exist = does_exist || exists;
            if (does_exist) {
                break;
            }
        }

        visited[curr_row][curr_col] = 0;

        return does_exist;
    }
};