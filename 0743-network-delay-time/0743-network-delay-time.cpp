class Solution {
public:

    // Time: O(ElogV)
    // Space: O(V)

    const int INF = INT_MAX;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj_list(n+1, vector<pair<int,int>>());
        for (auto& vec : times) {
            int src = vec[0],
                dest = vec[1],
                duration = vec[2];

            adj_list[src].push_back({ dest, duration });
        }

        vector<int> dist(n+1, INF);

        findSingleSourceShortestTimes(
            adj_list,
            n,
            k,
            dist
        );

        int max_time_required = 0;
        for (int i = 1; i <= n; i++) {
            int d = dist[i];
            if (i == k) {
                continue;
            }

            max_time_required = max(max_time_required, d);
        }

        return max_time_required == INF ? -1 : max_time_required;
    }

    void findSingleSourceShortestTimes(
        vector<vector<pair<int,int>>>& adj_list,
        int n,
        int k,
        vector<int>& dist
    ) {

        vector<int> vis(n+1, 0);
        auto cmp = [&](auto& s1, auto& s2) {
            return s1.first > s2.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> node_queue(cmp);

        dist[k] = 0;
        node_queue.push({ dist[k], k });
        vis[k] = 1;

        while (!node_queue.empty()) {
            auto [ _, curr_node ] = node_queue.top();
            node_queue.pop();

            if (vis[curr_node] == 2)
                continue;

            for (auto& [ next_node, duration ] : adj_list[curr_node]) {
                if (dist[next_node] > dist[curr_node] + duration) {
                    dist[next_node] = dist[curr_node] + duration;
                    node_queue.push({ dist[next_node], next_node });
                    vis[next_node] = 1;
                }
            }

            vis[curr_node] = 2;
        }
    }
};