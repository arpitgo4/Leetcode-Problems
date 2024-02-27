/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // Time: O(N)
    // Space: O(N)
    
    bool same_tree(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
                return true;
        if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
            return false;
        if (root1->val != root2->val)
            return false;
        
        bool a = same_tree(root1->left, root2->left);
        bool b = same_tree(root1->right, root2->right);
        
        return a & b;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;
        
        bool found = false;
        if (root->val == subRoot->val)
            found = found || same_tree(root, subRoot);
        
        bool a = isSubtree(root->left, subRoot);
        bool b = isSubtree(root->right, subRoot);
            
        return found || a || b;
    }
};