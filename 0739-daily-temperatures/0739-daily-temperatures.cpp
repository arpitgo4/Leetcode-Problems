class Solution {
public:

    // Time: O(N)
    // Space: O(N)

    // Monotonic Stack

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperature_cnt = temperatures.size();
        vector<int> result(temperature_cnt, 0);
        stack<int> mono_stack;                                // monotonically decreasing stack
        for (int i = temperature_cnt-1; i >= 0; i--) {
            while (!mono_stack.empty() && temperatures[mono_stack.top()] <= temperatures[i]) {
                mono_stack.pop();
            }

            if (!mono_stack.empty()) {
                result[i] = mono_stack.top() - i;
            }

            mono_stack.push(i);
        }

        return result;
    }
};