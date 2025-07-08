class Solution {
public:

    // Time: O(N * M)
    // Space: O(N * M)

    const vector<pair<int,int>> moves{
        { -1, 0 },                  // up
        { 1, 0 },                   // down
        { 0, -1 },                  // left
        { 0, 1 }                    // right
    };

    class QueueState {
    public:
        int curr_i_;
        int curr_j_;
        int curr_health_;
        QueueState(int i, int j, int health) {
            curr_i_ = i;
            curr_j_ = j;
            curr_health_ = health;
        };
    };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row_size = grid.size(),
            col_size = grid[0].size();

        int start_i = 0,
            start_j = 0;

        vector<vector<int>> vis(row_size, vector<int>(col_size, 0));

        deque<QueueState> cell_queue;
        cell_queue.emplace_back(start_i, start_j, health-grid[start_i][start_j]);
        vis[start_i][start_j] = 1;

        while (!cell_queue.empty()) {
            auto [ curr_i, curr_j, curr_health ] = cell_queue.front();
            cell_queue.pop_front();

            if (vis[curr_i][curr_j] == 2 || curr_health == 0) {
                continue;
            }
            if (curr_i == row_size-1 && curr_j == col_size-1) {
                return true;
            }

            for (auto& [di, dj] : moves) {
                int next_i = curr_i + di;
                int next_j = curr_j + dj;

                if (next_i >= 0 && 
                    next_i < row_size && 
                    next_j >= 0 && 
                    next_j < col_size && 
                    vis[next_i][next_j] == 0) {
                        if (grid[next_i][next_j] == 0) {
                            cell_queue.emplace_front(next_i, next_j, curr_health);
                        } else {
                            cell_queue.emplace_back(next_i, next_j, curr_health-1);
                        }

                        vis[next_i][next_j] = 1;
                    }
            }

            vis[curr_i][curr_j] = 2;
        }

        return false;
    }

};