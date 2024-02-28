class Solution {
public:

    // Time: O(MAX_W * ALPHA_SIZE)
    // Space: O(MAX_W * ALPHA_SIZE)
    
    const int MAX_W = 200;
    const int ALPHA_SIZE = 26;
    vector<vector<int>> trie;
    
    void insert(string& S) {
        int i = 0, j = 0;
        for (char c : S) {
            j = c - 'a';
            trie[i][j]++;
            i++;
        }
    }
    
    string dfs(int i, int N) {
        if (i == MAX_W)
            return "";
        
        for (int j = 0; j < ALPHA_SIZE; j++) {
            if (trie[i][j] == N)                            // for all strings to have same prefix at depth i, count at trie(i,j) == N
                return char(j + 'a') + dfs(i+1, N);
        }
        
        return "";
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        trie.assign(MAX_W, vector<int>(ALPHA_SIZE, 0));
        
        for (string& s : strs)
            insert(s);
        
        return dfs(0, strs.size());
    }
};