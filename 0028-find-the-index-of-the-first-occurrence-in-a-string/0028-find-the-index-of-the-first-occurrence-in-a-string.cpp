class Solution {
public:
    
    // Time: O(N + M)
    // Space: O(N + M)
    
    vector<int> pi;
    
    void prefix_function(string& S) {
        int N = S.length();
        pi.assign(N, 0);
        for (int i = 1; i < N; i++) {
            int j = pi[i-1];
            while (j > 0 && S[i] != S[j])
                j = pi[j-1];
            if (S[i] == S[j])
                j++;
            pi[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        string str = needle + '$' + haystack;
        prefix_function(str);
        
        int M = needle.length();
        for (int i = M+1; i < str.length(); i++)
            if (pi[i] == M)
                return (i-(2*M));
        
        return -1;
    }
};