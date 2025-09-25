class Solution {
public:
    vector<vector<int>> generate(int N) {
        vector<vector<int>> result;
        if (N == 0)
            return result;
        
        int rows = N, cols = 2*N-1;
        int A[rows][cols];
        
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                A[i][j] = 0;
        
        int m = cols / 2;
        A[0][m] = 1;
        
        for (int i = 1; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                int a = 0, b = 0;
                if (j-1 >= 0)
                    a = A[i-1][j-1];
                if (j+1 < cols)
                    b = A[i-1][j+1];

                A[i][j] = a + b;
            }
                    
        for (int i = 0; i < rows; i++) {
            vector<int> v;
            for (int j = 0; j < cols; j++) {
                if (A[i][j] != 0)
                    v.push_back(A[i][j]);   
            }
            result.push_back(v);
        }
        
        return result;
    }
};
