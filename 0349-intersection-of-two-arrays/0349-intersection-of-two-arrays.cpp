class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> nums1_set;
        for (int num : nums1) {
            nums1_set.insert(num);
        }

        set<int> intersection_set;
        for (int num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                intersection_set.insert(num);
            }
        }

        vector<int> result;
        for (int num : intersection_set) {
            result.push_back(num);
        }

        return result;
    }
};