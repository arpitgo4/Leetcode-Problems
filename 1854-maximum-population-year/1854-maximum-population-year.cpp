class Solution {
public:
    
    // Time: O(NlogN)
    // Space: O(N)
    
    int maximumPopulation(vector<vector<int>>& logs) {
        int N = logs.size();
        vector<pair<int,int>> A(2*N);
        
        int j = 0;
        for (int i = 0; i < N; i++) {
            A[j] = { logs[i][0], 1 };                   // birth
            A[j+1] = { logs[i][1], -1 };                // death
            j += 2;
        }
        
        sort(A.begin(), A.end(), [&](const auto& p1, const auto& p2) {
            if (p1.first == p2.first)
                return p1.second < p2.second;
            return p1.first < p2.first;
        });
        
        int counter = 0, max_counter = 0, max_year = -1;
        for (int i = 0; i < 2*N; i++) {
            counter += A[i].second;
            
            if (counter > max_counter) {
                max_counter = counter;
                max_year = A[i].first;
            }
        }
        
        return max_year;
    }
};