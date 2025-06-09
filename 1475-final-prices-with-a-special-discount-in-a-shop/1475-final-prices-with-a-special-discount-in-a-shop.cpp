class Solution {
public:

    // Time: O(N)
    // Space: O(N)

    // Monotonic Stack

    vector<int> finalPrices(vector<int>& prices) {
        int prices_cnt = prices.size();

        vector<int> result(prices_cnt, 0);
        stack<int> mono_stack;                                  // monotonically decreasing stack
        for (int i = prices_cnt-1; i >= 0; i--) {
            while (!mono_stack.empty() && mono_stack.top() > prices[i]) {
                mono_stack.pop();
            }

            int discount = 0;
            if (!mono_stack.empty()) {
                discount = mono_stack.top();                    // prev_smaller_price
            }

            result[i] = prices[i] - discount;

            mono_stack.push(prices[i]);
        }

        return result;
    }
};