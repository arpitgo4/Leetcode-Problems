class Solution {
public:

    // Time: O(N^2 * logN)
    // Space: O(N^2)

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<int> matrix_indices(rows * cols);
        iota(matrix_indices.begin(), matrix_indices.end(), 0);

        sort(matrix_indices.begin(), matrix_indices.end(), [&](auto& id1, auto& id2) {
            pair<int,int> coord_1 = get2DCoordById(id1, cols);
            pair<int,int> coord_2 = get2DCoordById(id2, cols);

            int dist_1 = calcManhDistance(
                coord_1.first, 
                coord_1.second, 
                rCenter, 
                cCenter
            );
            int dist_2 = calcManhDistance(
                coord_2.first, 
                coord_2.second, 
                rCenter, 
                cCenter
            );

            return dist_1 < dist_2;
        });

        vector<vector<int>> result;
        for (int idx : matrix_indices) {
            pair<int,int> coord = get2DCoordById(idx, cols);
            result.emplace_back(
                vector<int>{ coord.first, coord.second }
            );
        }

        return result;
    }

    pair<int,int> get2DCoordById(int id, int col) {
        return {
            id / col,
            id % col
        };
    }

    int calcManhDistance(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }
};