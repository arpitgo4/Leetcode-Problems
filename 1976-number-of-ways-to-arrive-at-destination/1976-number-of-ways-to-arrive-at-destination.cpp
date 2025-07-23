class Solution {
public:

    // Time: O(ElogE)
    // Space: O(V + E)

    using ll_t = long long;
    using graph_edge_t = pair<int,ll_t>;
    using graph_t = vector<vector<graph_edge_t>>;
    using queue_state_t = pair<ll_t,int>;

    const ll_t MOD = 1e9 + 7;
    const ll_t INF = LLONG_MAX;

    int countPaths(int intersec_cnt, vector<vector<int>>& roads) {
        graph_t adj_list(intersec_cnt, vector<graph_edge_t>());
        for (auto& edge : roads) {
            int intersec_1 = edge[0],
                intersec_2 = edge[1];
            ll_t time = edge[2];
            adj_list[intersec_1].emplace_back(intersec_2, time);
            adj_list[intersec_2].emplace_back(intersec_1, time);
        }

        ll_t ways_cnt = countNumberOfShortestPaths(
            0,
            intersec_cnt-1,
            adj_list,
            intersec_cnt
        ); 

        return ways_cnt;
    }

    ll_t countNumberOfShortestPaths(
        int src,
        int dest,
        graph_t& adj_list,
        int intersec_cnt
    ) {
        vector<int> vis(intersec_cnt, 0);
        vector<ll_t> dist(intersec_cnt, INF);
        vector<ll_t> path_cnt(intersec_cnt, 0);

        auto cmp = [&](auto& s1, auto& s2) {
            return s1.first > s2.first;
        };
        priority_queue<queue_state_t, vector<queue_state_t>, decltype(cmp)> intersec_queue(cmp);

        dist[src] = 0;
        path_cnt[src] = 1;
        intersec_queue.emplace(dist[src], src);

        while (!intersec_queue.empty()) {
            auto [ curr_time, curr_intersec ] = intersec_queue.top();
            intersec_queue.pop();

            if (curr_time > dist[curr_intersec])
                continue;

            for (auto& [ next_intersec, time_required ] : adj_list[curr_intersec]) {
                if (dist[next_intersec] > dist[curr_intersec] + time_required) {
                    dist[next_intersec] = dist[curr_intersec] + time_required;
                    intersec_queue.emplace(dist[next_intersec], next_intersec);
                    path_cnt[next_intersec] = path_cnt[curr_intersec];
                } else if (dist[next_intersec] == dist[curr_intersec] + time_required) {
                    path_cnt[next_intersec] = (path_cnt[next_intersec] + path_cnt[curr_intersec]) % MOD;
                }
            }
        }

        return path_cnt[dest];
    }
};