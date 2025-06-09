class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)

    // change this to Maximum Segment Tree instead of Sum Segment Tree
    class MaxSegmentTree {
    public:
        MaxSegmentTree(vector<int>& arr) {
            int arr_size = arr.size();
            tree_.assign(arr_size * 4, NEG_INF);
            buildTree(0, arr_size-1, 0, arr);
        }

        void buildTree(int low, int high, int node_idx, vector<int>& arr) {
            if (low == high) {
                tree_[node_idx] = arr[low];
                return;
            }

            int mid = (high - low) / 2 + low;
            buildTree(low, mid, 2*node_idx+1, arr);
            buildTree(mid+1, high, 2*node_idx+2, arr);

            tree_[node_idx] = max(tree_[2*node_idx+1], tree_[2*node_idx+2]);
        }

        int queryLeftMost(int low, int high, int node_idx, int fruit_cnt) {
            if (low == high) {
                return tree_[node_idx] >= fruit_cnt ? low : -1;
            }

            int mid = (high - low) / 2 + low;
            if (tree_[2*node_idx+1] >= fruit_cnt) {
                return queryLeftMost(low, mid, 2*node_idx+1, fruit_cnt);
            } else {
                return queryLeftMost(mid+1, high, 2*node_idx+2, fruit_cnt);
            }
        }

        void update(int low, int high, int node_idx, int update_idx) {
            if (low == high && low == update_idx) {
                tree_[node_idx] = NEG_INF;
                return;
            }

            int mid = (high - low) / 2 + low;
            if (update_idx <= mid) {
                update(low, mid, 2*node_idx+1, update_idx);
            } else {
                update(mid+1, high, 2*node_idx+2, update_idx);
            }

            tree_[node_idx] = max(tree_[2*node_idx+1], tree_[2*node_idx+2]);
        }

    private:
        const int NEG_INF = INT_MIN;
        vector<int> tree_;
    };

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int basket_size = baskets.size();
        int fruits_size = fruits.size();

        MaxSegmentTree basket_tree(baskets);

        int unplaced_cnt = 0;
        for (int i = 0; i < fruits_size; i++) {
            int avail_basket_idx = basket_tree.queryLeftMost(0, basket_size-1, 0, fruits[i]);
            if (avail_basket_idx != -1) {
                basket_tree.update(0, basket_size-1, 0, avail_basket_idx);
            } else {
                unplaced_cnt++;
            }
        }

        return unplaced_cnt;
    }
};