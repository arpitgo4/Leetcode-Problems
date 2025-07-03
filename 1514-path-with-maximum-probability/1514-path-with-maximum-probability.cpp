class Solution {
public:

    // Time: O(ElogV)
    // Space: O(V)

    using edge_t = pair<int,double>;
    using state_t = pair<double,int>;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<edge_t>> adj_list(n+1, vector<edge_t>());
        int edge_idx = 0;
        for (auto& edge : edges) {
            int node_a = edge[0],
                node_b = edge[1];
            double succ_prob = succProb[edge_idx];

            adj_list[node_a].push_back({ node_b, succ_prob });
            adj_list[node_b].push_back({ node_a, succ_prob });
            edge_idx++;
        }

        vector<double> dist(n+1, 0.0f);
        findMaxProbabilityFromSingleNode(
            adj_list,
            n,
            start_node,
            dist
        );

        cout << fixed << setprecision(5);
        
        return dist[end_node];
    }

    void findMaxProbabilityFromSingleNode(
        vector<vector<edge_t>>& adj_list,
        int n,
        int start_node,
        vector<double>& dist
    ) {

        vector<int> vis(n+1, 0);
        priority_queue<state_t> node_queue;

        dist[start_node] = 1.0f;
        node_queue.push({ dist[start_node], start_node });
        vis[start_node] = 1;

        while (!node_queue.empty()) {
            auto [ _, curr_node ] = node_queue.top();
            node_queue.pop();

            if (vis[curr_node] == 2)
                continue;

            for (auto& [ next_node, succ_prob ] : adj_list[curr_node]) {
                if (dist[next_node] < dist[curr_node] * succ_prob) {
                    dist[next_node] = dist[curr_node] * succ_prob;
                    node_queue.push({ dist[next_node], next_node });
                    vis[next_node] = 1;
                }
            }

            vis[curr_node] = 2;
        }
    }
};