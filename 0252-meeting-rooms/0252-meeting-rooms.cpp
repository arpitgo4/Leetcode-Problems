class Solution {
public:
    
    // Time: O(NlogN)
    // Space: O(N)
    
    bool canAttendMeetings(vector<vector<int>>& A) {
        map<int,int> line;
        for (auto& v : A) {
            line[v[0]]++;
            line[v[1]]--;
        }
        
        int count = 0;
        for (auto& p : line) {
            count += p.second;
            if (count > 1)
                return false;
        }
        
        return true;
    }
};