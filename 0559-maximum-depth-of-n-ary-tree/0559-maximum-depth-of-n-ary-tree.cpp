class Solution {
public:
    
    // Time: O(N)
    // Space: O(N)
    
    int dfs(Node* root) {
        if (root == NULL)
            return 0;
        
        int max_depth = 1;
        for (Node* child : root->children)
            max_depth = max(max_depth, 1 + dfs(child));
        
        return max_depth;
    }
    
    int maxDepth(Node* root) {
        return dfs(root);
    }
};