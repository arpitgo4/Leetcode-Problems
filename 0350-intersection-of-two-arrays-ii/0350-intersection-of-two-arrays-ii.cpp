class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> nums1_set;
        for (int num : nums1) {
            nums1_set.insert(num);
        }

        vector<int> intersection_set;
        for (int num : nums2) {
            if (nums1_set.find(num) != nums1_set.end()) {
                nums1_set.erase(nums1_set.find(num));
                intersection_set.push_back(num);
            }
        }

        return intersection_set;
    }
};