class Solution {
public:

    // Time: O(NlogN)
    // Space: O(N)

    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> line;
        for (auto& interval : intervals) {
            line[interval[0]]++;
            line[interval[1]]--;
        }

        int max_room_cnt = 0;
        int room_cnter = 0;
        for (auto& [ time, cnt ] : line) {
            room_cnter += cnt;
            max_room_cnt = max(max_room_cnt, room_cnter);
        }

        return max_room_cnt;
    }
};