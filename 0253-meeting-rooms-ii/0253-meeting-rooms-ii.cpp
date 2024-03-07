class Solution {
public:
    
    // Time: O(NlogN)
    // Space: O(N)
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int N = intervals.size();
        
        int j = 0;
        vector<pair<int,int>> A(2*N);
        for (int i = 0; i < N; i++) {
            A[j++] = { intervals[i][0], 1 };
            A[j++] = { intervals[i][1], -1 };
        }
        
        sort(A.begin(), A.end(), [&](const auto& p1, const auto& p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        int max_count = 0;
        int count = 0;
        for (int i = 0; i < 2*N; i++) {
            count += A[i].second;
            max_count = max(max_count, count);
        }
        
        return max_count;
    }
};