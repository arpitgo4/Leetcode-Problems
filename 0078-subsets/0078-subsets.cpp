class Solution {
public:

    // Time: O(2^N)
    // Space: O(2^N)
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr_set;
        vector<vector<int>> power_set;
        findSubsets(
            0,
            curr_set,
            nums,
            power_set
        );

        return power_set;
    }

    void findSubsets(
        int idx,
        vector<int>& curr_set,
        vector<int>& nums,
        vector<vector<int>>& power_set
    ) {
        if (idx == nums.size()) {
            power_set.push_back(curr_set);
            return;
        }

        // include
        curr_set.push_back(nums[idx]);
        findSubsets(
            idx + 1,
            curr_set,
            nums,
            power_set
        );

        // exclude
        curr_set.pop_back();
        findSubsets(
            idx + 1,
            curr_set,
            nums,
            power_set
        );
    }
};