#include "../../include/leetcode.hpp"

class NumMatrix {
public:
    vector<vector<int>> sumTo;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        init(sumTo, m, n);
        
        int i, j;
        int sum;
        for (i = 0; i < m; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                sum += matrix[i][j];
                if (i == 0)
                    sumTo[i][j] = sum;
                else
                    sumTo[i][j] = sum + sumTo[i - 1][j];
            }
        }
    }
    
    void init(vector<vector<int>> vec, int m, int n) {
        int i;
        for (i = 0; i < m; i++) {
            vec.push_back(vector<int>(n, 1));
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return sumTo[row2][col2];
        }
        if (row1 == 0) {
            return sumTo[row2][col2] - sumTo[row2][col1 - 1];
        }
        if (col1 == 0) {
            return sumTo[row2][col2] - sumTo[row1 - 1][col2];
        }
        return sumTo[row2][col2] - (sumTo[row1 - 1][col2] + sumTo[row2][col1 - 1]) + sumTo[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
