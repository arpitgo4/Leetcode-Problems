class Solution {
public:
    
    // Time: O(logN)
    // Space: O(1)
    
    #define NEG_INF LLONG_MIN
    typedef long long ll;
    
    int findPeakElement(vector<int>& A) {
        int N = A.size();
        int l = 0, h = N-1;
        
        while (l <= h) {
            int m = ((h-l) >> 2) + l;
            ll left = (m-1 < 0 ? NEG_INF : A[m-1]);
            ll right = (m+1 == N ? NEG_INF : A[m+1]);
            
            if (left < A[m] && A[m] < right)
                l = m+1;
            else if (left > A[m] && A[m] > right)
                h = m-1;
            else if (left > A[m] && A[m] < right)
                h = m-1;
            else
                return m;
        }
        
        return -1;
    }
};