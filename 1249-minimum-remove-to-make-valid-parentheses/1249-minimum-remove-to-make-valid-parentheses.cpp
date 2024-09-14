class Solution {
public:
    
    // Time: O(N)
    // Space: O(N)
    
    string minRemoveToMakeValid(string S) {
        int N = S.length();
        vector<bool> marked(N, false);
        
        stack<pair<char,int>> st;
        for (int i = 0; i < N; i++) {
            char c = S[i];
            if (c == '(')
                st.push({ c, i });
            else if (c == ')') {
                if (!st.empty() && st.top().first == '(')
                    st.pop();
                else marked[i] = true;
            }
        }
        
        while (!st.empty()) {
            marked[st.top().second] = true;
            st.pop();
        }
        
        string result = "";
        for (int i = 0; i < N; i++)
            if (!marked[i])
                result += S[i];
        
        return result;
    }
};