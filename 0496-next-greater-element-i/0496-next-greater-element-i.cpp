class Solution {
public:

    // Time: O(N)
    // Space: O(N)
    vector<int> nextGreaterElement(vector<int>& A, vector<int>& B) {
        stack<int> mono_stack;                      // monotonically decreasing stack
        vector<int> next_greater(B.size(), -1);
        for (int i = B.size()-1; i >= 0; i--) {
            while (!mono_stack.empty() && mono_stack.top() < B[i]) {
                mono_stack.pop();
            }

            if (!mono_stack.empty() && mono_stack.top() > B[i]) {
                next_greater[i] = mono_stack.top();
            }

            mono_stack.push(B[i]);
        }

        unordered_map<int,int> b_map;
        for (int i = 0; i < B.size(); i++) {
            b_map[B[i]] = i;
        }

        vector<int> result(A.size());
        for (int i = 0; i < A.size(); i++) {
            int idx = b_map[A[i]];
            result[i] = next_greater[idx];
        }

        return result;
    }
};