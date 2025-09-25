class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice_total = 0;
        for (int candy_cnt : aliceSizes) {
            alice_total += candy_cnt;
        }

        int bob_total = 0;
        for (int candy_cnt : bobSizes) {
            bob_total += candy_cnt;
        }

        sort(bobSizes.begin(), bobSizes.end());

        vector<int> result;
        for (int candy_cnt : aliceSizes) {
            int target = (bob_total + 2 * candy_cnt - alice_total) / 2;

            auto itr = lower_bound(bobSizes.begin(), bobSizes.end(), target);
            if (itr != bobSizes.end() && *itr == target) {
                result.emplace_back(candy_cnt);
                result.emplace_back(*itr);
                return result;
            }
        }

        return result;
    }
};