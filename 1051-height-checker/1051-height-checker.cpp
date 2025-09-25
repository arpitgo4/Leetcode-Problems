class Solution {
public:

    // Time: O(N)
    // Space: O(1)

    const int MAX_HEIGHT = 100;

    int heightChecker(vector<int>& heights) {
        int student_cnt = heights.size();
        
        vector<int> count_tbl(MAX_HEIGHT+1, 0);
        for (int height : heights) {
            count_tbl[height]++;
        }

        int outplace_cnt = 0;
        int j = 1;
        for (int i = 0 ; i < student_cnt; i++) {
            while (count_tbl[j] == 0) {
                j++;
            }

            if (heights[i] != j) {
                outplace_cnt++;
            }

            count_tbl[j]--;
        }

        return outplace_cnt;
    }
};