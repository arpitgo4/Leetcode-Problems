class Solution {
public:
    
    // Time: O(NlogN)
    // Space: O(N)
    
    // align different meeting into groups
    // number of groups is the number of conference rooms required
    
    // each conference room will have a separate timeline
    // align all meetings in different timelines
    // number of timelines required for none of the meeting to conflict is the 
    // number of conference rooms required
    
    bool meeting_conflict(vector<int>& v1, vector<int>& v2) {
        if (v1[0] > v2[0])
            swap(v1, v2);
        
        return v1[1] > v2[0];
    }
    
    int minMeetingRooms(vector<vector<int>>& A) {
        int N = A.size();
        sort(A.begin(), A.end(), [&](const auto& v1, const auto& v2) {
            return v1[0] < v2[0];                                                    // sort by start-time
        });
        
        auto comp = [&](const auto& v1, const auto& v2) {
            return v1[1] > v2[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);   // min-heap by end-time
        
        pq.push(A[0]);
        for (int i = 1; i < N; i++) {
            auto curr = pq.top();
            if (!meeting_conflict(curr, A[i]))
                pq.pop();
            
            pq.push(A[i]);
        }
        
        return pq.size();
    }
};