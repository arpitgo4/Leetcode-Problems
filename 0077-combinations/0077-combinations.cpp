class Solution {
public:

    // Time: O(nCk)
    // Space: O(nCk)

    vector<vector<int>> combine(int total, int choose) {
        vector<vector<int>> result;
        combinations(1, 0, total, choose, result);

        return result;
    }

    void combinations(
        int curr_num,
        int mask,
        int total,
        int choose,
        vector<vector<int>>& result
    ) {
        if (__builtin_popcount(mask) > choose) {
            return;
        }
        if (__builtin_popcount(mask) == choose) {
            vector<int> subset;
            for (int i = 1; i <= total; i++) {
                if (mask & (1 << i)) {
                    subset.emplace_back(i);
                }
            }

            result.emplace_back(subset);
            return;
        }
        if (curr_num > total) {
            return;
        }

        // include curr_num
        combinations(
            curr_num + 1,  
            (mask | (1 << curr_num)),
            total,
            choose,
            result
        );

        // exclude curr_num
        combinations(
            curr_num + 1,  
            mask,
            total,
            choose,
            result
        );
    }
};