class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)

    vector<int> twoSum(vector<int>& nums, int target) {
        int num_cnt = nums.size();

        vector<int> order_nums(num_cnt);
        iota(order_nums.begin(), order_nums.end(), 0);

        auto cmp = [&](auto& a, auto& b) {
            return nums[a] < nums[b];
        };
        sort(order_nums.begin(), order_nums.end(), cmp);
        
        int i = 0, j = num_cnt-1;
        while (i < j) {
            int sum = nums[order_nums[i]] + nums[order_nums[j]];
            if (sum == target) {
                return vector<int>{ order_nums[i], order_nums[j] };
            } else if (sum < target) {
                i++;
            } else {
                j--;
            };
        }

        return { -1, -1 };
    }
};