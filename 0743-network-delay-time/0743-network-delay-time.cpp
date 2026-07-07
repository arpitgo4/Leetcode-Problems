using edge_t = pair<int,int>;
using graph_t = vector<vector<edge_t>>;
using state_t = pair<int,int>;

const int INF = INT_MAX;
 
class Solution {
public:

    // Time: O(ElogV)
    // Space: O(V)

    int networkDelayTime(
        vector<vector<int>>& connections,
        int node_cnt,
        int source_node
    ) {
        graph_t adj_list(node_cnt+1, vector<edge_t>());

        for (vector<int>& connection : connections) {
            int source_node = connection[0];
            int dest_node = connection[1];
            int latency = connection[2];

            adj_list[source_node].push_back({ dest_node, latency });
        }

        vector<int> least_latency(node_cnt+1, INF);

        findLeastLatencyFromSource(
            adj_list,
            node_cnt,
            source_node,
            least_latency
        );

        bool all_nodes_reachable = true;
        int max_latency = -1;
        for (int i = 1; i <= node_cnt; i++) {
            if (least_latency[i] == INF) {
                all_nodes_reachable = false;
                break;
            }

            max_latency = max(max_latency, least_latency[i]);
        }

        return !all_nodes_reachable ? -1 : max_latency;
    }

    void findLeastLatencyFromSource(
        graph_t& adj_list,
        int node_cnt,
        int source_node,
        vector<int>& least_latency
    ) {
        least_latency[source_node] = 0;

        vector<int> vis(node_cnt+1, 0);

        auto cmp = [&](auto& s1, auto& s2) {
            return s1.first > s2.first;
        };
        priority_queue<state_t, vector<state_t>, decltype(cmp)> node_queue(cmp);
        node_queue.push({ least_latency[source_node], source_node });

        while(!node_queue.empty()) {
            auto [ curr_latency, curr_node ] = node_queue.top();
            node_queue.pop();

            if (vis[curr_node] != 0) {
                continue;
            }

            vis[curr_node] = 1;

            for (edge_t& connection : adj_list[curr_node]) {
                auto [ next_node, next_latency ] = connection;
                if (least_latency[next_node] > least_latency[curr_node] + next_latency) {
                    least_latency[next_node] = least_latency[curr_node] + next_latency;
                    node_queue.push({ least_latency[next_node], next_node });
                }
            }
        }
    }
};