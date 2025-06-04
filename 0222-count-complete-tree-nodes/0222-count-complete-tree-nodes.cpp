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

    // Time: O((logN)^2)
    // Space: O(logN)

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int low = 1, high = 5 * 1e4;
        while (low <= high) {
            int mid = ((high - low) / 2) + low;
            bool node_found = findNodeByIndex(root, mid);
            if (node_found) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return low;
    }

    bool findNodeByIndex(TreeNode* root, int target_index) {
        stack<int> node_vals_till_par;
        int curr_val = target_index;
        while (curr_val > 0) {
            node_vals_till_par.push(curr_val);
            curr_val = (curr_val - 1) / 2;
        }

        bool target_node_found = dfs(root, 0, node_vals_till_par);
        return target_node_found;
    }

    bool dfs(TreeNode* root, int curr_node_idx, stack<int>& node_vals) {
        if (root == NULL)
            return false;
        if (node_vals.empty()) {
            return true;
        }

        int left_idx = curr_node_idx * 2 + 1;
        int right_idx = left_idx + 1;

        if (left_idx == node_vals.top()) {
            node_vals.pop();
            return dfs(root->left, left_idx, node_vals);
        } else {
            node_vals.pop();
            return dfs(root->right, right_idx, node_vals);
        }
    }
};