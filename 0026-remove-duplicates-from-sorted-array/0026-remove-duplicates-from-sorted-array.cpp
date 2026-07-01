class Solution {
public:

    // Time: O(N)
    // Space: O(1)
    int removeDuplicates(vector<int>& nums) {
        int num_cnt = nums.size();
        int j = 1;
        for (int i = 1; i < num_cnt; i++) {
            if (nums[i] != nums[i-1]) {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};