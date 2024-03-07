class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) {
        map<int,int> line;
        for (auto& v : A) {
            line[v[0]]++;
            line[v[1]]--;
        }
        
        int max_count = 0, count = 0;
        for (auto& p : line) {
            count += p.second;
            max_count = max(max_count, count);
        }
        
        return max_count;
    }
};