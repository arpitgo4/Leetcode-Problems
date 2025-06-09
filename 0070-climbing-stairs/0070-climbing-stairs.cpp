class Solution {
public:

    // Time: O(N)
    // Space: O(N)

    int climbStairs(int step_cnt) {
        vector<int> dp(step_cnt+1, -1);

        return countWaysToClimb(0, step_cnt, dp);
    }

    int countWaysToClimb(int curr_step, int step_cnt, vector<int>& dp) {
        if (curr_step > step_cnt)
            return INT_MAX;
        if (curr_step == step_cnt)
            return 1;
        if (dp[curr_step] != -1)
            return dp[curr_step];

        int total_ways = 0;
        int ways_by_one = countWaysToClimb(curr_step + 1, step_cnt, dp);
        if (ways_by_one != INT_MAX) {
            total_ways += ways_by_one;
        }
        int ways_by_two = countWaysToClimb(curr_step + 2, step_cnt, dp); 
        if (ways_by_two != INT_MAX) {
            total_ways += ways_by_two;
        }

        return dp[curr_step] = total_ways;
    }
};