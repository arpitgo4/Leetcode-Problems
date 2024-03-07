class Solution {
public:
    
    // Time: O(NlogN)
    // Space: O(N)
    
    // overlapping segment(s) -> merge all of them iteratively and count
    // non-overlapping segments(s) -> count all of them seperately
    
    bool is_overlapping(int a, int b, int c, int d) {
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        
        return (c >= a && c <= b) || (d >= a && d <= b);
    }
    
    int numberOfPoints(vector<vector<int>>& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        
        int curr_s = A[0][0], curr_e = A[0][1];
        int count = 0;
        for (int i = 1; i < N; i++) {
            if (is_overlapping(curr_s, curr_e, A[i][0], A[i][1])) {
                curr_s = min(curr_s, A[i][0]);
                curr_e = max(curr_e, A[i][1]);
            } else {
                count += curr_e - curr_s + 1;
                curr_e = A[i][1];
                curr_s = A[i][0];
            }
        }
        
        count += curr_e - curr_s + 1;
        
        return count;
    }
};