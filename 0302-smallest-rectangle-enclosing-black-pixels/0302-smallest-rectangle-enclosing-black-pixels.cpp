class Solution {
public:
    
    // Time: O(NlogM + MlogN)
    // Space: O(1)
    
    int lower_bound_row(vector<vector<char>>& A, int h, int N, int M) {
        int l = 0;
        while (l <= h) {
            int m = (h-l)/2 + l;
            if (check_row(A, m, N, M))
                h = m-1;
            else l = m+1;
        }
        
        return l;
    }
    
    int upper_bound_row(vector<vector<char>>& A, int l, int N, int M) {
        int h = N-1;
        while (l <= h) {
            int m = (h-l)/2 + l;
            if (check_row(A, m, N, M))
                l = m+1;
            else h = m-1;
        }
        
        return h;
    }
    
    bool check_row(vector<vector<char>>& A, int m, int N, int M) {
        for (int i = 0; i < M; i++)
            if (A[m][i] == '1')
                return true;
        return false;
    }
    
    int minArea(vector<vector<char>>& A, int x, int y) {
        int N = A.size();
        int M = A[0].size();
        
        cout << "Width: " << endl;
        cout << "lower_bound: " << lower_bound_col(A, y, N, M) << endl;
        cout << "upper_bound: " << upper_bound_col(A, y, N, M) << endl;
        
        cout << "Length: " << endl;
        cout << "lower_bound: " << lower_bound_row(A, x, N, M) << endl;
        cout << "upper_bound: " << upper_bound_row(A, x, N, M) << endl;
    
        int w = upper_bound_col(A, y, N, M) - lower_bound_col(A, y, N, M) + 1;
        int l = upper_bound_row(A, x, N, M) - lower_bound_row(A, x, N, M) + 1;
        
        cout << "w: " << w << ", l: " << l << endl;
        
        return l * w;
    }
    
    int lower_bound_col(vector<vector<char>>& A, int h, int N, int M) {
        int l = 0;
        while (l <= h) {
            int m = (h-l)/2 + l;
            if (check_col(A, m, N, M))
                h = m-1;
            else l = m+1;
        }
        
        return l;
    }
    
    int upper_bound_col(vector<vector<char>>& A, int l, int N, int M) {
        int h = M-1;
        while (l <= h) {
            int m = (h-l)/2 + l;
            if (check_col(A, m, N, M))
                l = m+1;
            else h = m-1;
        }
        
        return h;
    }
    
    bool check_col(vector<vector<char>>& A, int m, int N, int M) {
        for (int i = 0; i < N; i++)
            if (A[i][m] == '1')
                return true;
        return false;
    }
};