class Solution {
public:

    // Time: O(log(N * M))
    // Space: O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_sz = matrix.size();
        int col_sz = matrix[0].size();
        int lower_bound = 0;
        int upper_bound = row_sz * col_sz - 1;
        while (lower_bound <= upper_bound) {
            int mid = (upper_bound - lower_bound) / 2 + lower_bound;
            auto [i, j] = get2DIndex(mid, col_sz);
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                lower_bound = mid+1;
            } else {
                upper_bound = mid-1;
            }
        }

        return false;
    }

    pair<int,int> get2DIndex(int idx, int col_sz) {
        return { 
            idx / col_sz,
            idx % col_sz
        };
    }
};