class Solution {
public:

    // Time: O(logN)
    // Space: O(1)
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = ((high - low) / 2) + low;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {                        // nums[mid] > target
                high = mid - 1;
            }
        }

        return -1;
    }
};