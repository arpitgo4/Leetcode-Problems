class Solution {
public:

    // Time: O(N)
    // Space: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            nums_map.insert({ nums[i], i });
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int b = target - a;
            if (nums_map.find(b) != nums_map.end()) {
                int j = nums_map.find(b)->second;
                if (j != i) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }

        return result;
    }
};