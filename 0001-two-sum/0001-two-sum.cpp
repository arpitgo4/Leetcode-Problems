class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)

    vector<int> twoSum(vector<int>& nums, int target) {
        int num_cnt = nums.size();

        vector<int> order_nums_idx(num_cnt);
        iota(order_nums_idx.begin(), order_nums_idx.end(), 0);

        auto cmp = [&](auto& a, auto& b) {
            return nums[a] < nums[b];
        };
        sort(order_nums_idx.begin(), order_nums_idx.end(), cmp);
        
        int i = 0, j = num_cnt-1;
        while (i < j) {
            int a = nums[order_nums_idx[i]];
            int b = nums[order_nums_idx[j]];
            int sum = a + b;
            if (sum == target) {
                return vector<int>{ 
                    order_nums_idx[i], 
                    order_nums_idx[j] 
                };
            } else if (sum < target) {
                i++;
            } else {
                j--;
            };
        }

        return { -1, -1 };
    }
};