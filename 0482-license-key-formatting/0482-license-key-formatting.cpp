class Solution {
public:
    
    // Time: O(N)
    // Space: O(N)
    
    string licenseKeyFormatting(string S, int k) {
        stack<char> st;
        
        int count = 0;
        int N = S.length();
        for (int i = N-1; i >= 0; i--) {
            if (S[i] == '-')
                continue;
            
            st.push(toupper(S[i]));
            count++;
            
            if (count % k == 0) {
                count = 0;
                st.push('-');
            }
        }
        
        string result = "";
        if (!st.empty() && st.top() == '-')
            st.pop();
        
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};