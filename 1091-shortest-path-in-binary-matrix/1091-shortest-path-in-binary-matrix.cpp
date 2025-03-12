class Solution {
public:

    class OneMoreClass {};

    // Time: O(N^2)
    // Space: O(N^2)

    vector<vector<int>> VIS;

    // if eastern cells are available (i.e. == 0) they are the first to be queued up as they
    // will reach destination in shorter distance compared to western cells
    // with above setup, we can prune the BFS as soon as we reach the destination
    vector<vector<int>> directions{
        { -1, 1 },       // north-east
        { 0, 1 },        // east
        { 1, 1 },        // south-east
        { -1, 0 },       // north
        { 1, 0 },         // south
        { 0, -1 },       // west
        { -1, -1 },      // north-west
        { 1, -1 }       // south-west
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& G) {
        OneMoreClass one_more_class;
        if (G[0][0] != 0)
            return -1;

        int N = G.size();
        VIS.assign(N, vector<int>(N, 0));

        queue<tuple<int,int,int>> q;
        q.push({ 0, 0, 1 });
            
        while (!q.empty()) {
            tuple<int,int,int> t = q.front();
            q.pop();

            int i, j, dist;
            tie(i, j, dist) = t;

            if (i == N-1 && j == N-1)
                return dist;

            if (VIS[i][j] != 0)
                continue;
            VIS[i][j] = 1;

            for (vector<int>& d : directions) {
                int x = d[0], y = d[1];
                if (i+x >= 0 && i+x < N && j+y >= 0 && j+y < N && G[i+x][j+y] == 0)
                    q.push({ i+x, j+y, dist+1 });
            }

        }

        return -1;
    }
};