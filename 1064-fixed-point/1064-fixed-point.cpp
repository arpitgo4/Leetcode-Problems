class Solution {
public:

    // Time: O(logN)
    // Space: O(1)
    int fixedPoint(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (arr[mid] == mid) {
                high = mid - 1;
            } else if (arr[mid] < mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (low < 0 || low >= arr.size() || arr[low] != low)
            return -1;

        return low;
    }
};