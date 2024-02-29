class Solution {
public:
    
    // MAX_W = 50
    // Time: O(MAX_W * ALPHA_SIZE + MAX_W * N ) ~ O(MAX_W * N)
    // Space: O(MAX_W * ALPHA_SIZE)
    
    static const int ALPHA_SIZE = 26;
    vector<vector<int>> res;
    
    class TrieNode {
        public:
            bool is_word;
            vector<TrieNode*> children;

            TrieNode() {
                this->is_word = false;
                this->children.assign(ALPHA_SIZE, NULL);
            }
    }root;
    
    void insert(string& S) {
        TrieNode* node = &root;
        for (char c : S) {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();
            
            node = node->children[idx];
        }
        
        node->is_word = true;
    }
    
    void dfs(int j, TrieNode* node, string& text, vector<int>& acc) { 
        if (node == NULL || j == text.length())
            return;
        
        int char_idx = text[j] - 'a';
        if (node->children[char_idx] == NULL)
            return;
        if (node->children[char_idx]->is_word)
            acc.push_back(j);
        
        dfs(j+1, node->children[char_idx], text, acc);
    }
    
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        for (string& s : words)
            insert(s);
        
        int N = text.length();
        for (int i = 0; i < N; i++) {
            vector<int> acc;
            dfs(i, &root, text, acc);
            
            for (int e : acc)
                res.push_back({ i, e });
        }
        
        return res;
    }
};