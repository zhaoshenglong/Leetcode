class Solution {
    int meanNormal(vector<vector<int>>& img, int i, int j) {
        int res = 0;

        res += img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] \
                + img[i][j - 1] + img[i][j] + img[i][j + 1] \
                + img[i + 1][j - 1] + img[i + 1][j]+ img[i + 1][j + 1];
        return res / 9;
    }

    int meanSide(vector<vector<int>>& img, int i, int j, int m, int n) {
        if (m == 1) {
            if (j == 0)
                return (img[0][0] + img[0][1]) / 2;
            else if (j == n - 1)
                return (img[0][n - 1] + img[0][n - 2]) / 2;
            else
                return (img[0][j - 1] + img[0][j] + img[0][j + 1]) / 3;
        }
        if (n == 1) {
            if (i == 0)
                return (img[0][0] + img[1][0]) / 2;
            else if (i == m - 1)
                return (img[m - 1][0] + img[m - 2][0]) / 2;
            else
                return (img[i - 1][0] + img[i][0] + img[i + 1][0]) / 3;
        }

        if (i == 0) {
            if (j == 0) {
                return (img[i][j] + img[i][j + 1] + img[i + 1][j] + img[i + 1][j + 1]) / 4;
            } else if (j == n - 1) {
                return (img[i][j - 1] + img[i][j] + img[i + 1][j - 1] + img[i + 1][j]) / 4;
            } else {
                return (img[i][j - 1] + img[i][j] + img[i][j + 1] + img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1]) / 6;
            }
        } else if(i == m - 1) {
            if (j == 0) {
                return (img[i][j] + img[i][j + 1] + img[i - 1][j] + img[i - 1][j + 1]) / 4;
            } else if (j == n - 1) {
                return (img[i][j - 1] + img[i][j] + img[i - 1][j - 1] + img[i - 1][j]) / 4;
            } else {
                return (img[i][j - 1] + img[i][j] + img[i][j + 1] + img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1]) / 6;
            }
        } else {
            if (j == 0) {
                return (img[i][j] + img[i][j + 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i + 1][j] + img[i + 1][j + 1]) / 6;
            } else {
                return (img[i][j] + img[i][j - 1] + img[i - 1][j] + img[i - 1][j - 1] + img[i + 1][j] + img[i + 1][j - 1]) / 6;
            }
        }
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int i, j;
        
        if (m == 1 && n == 1)
            return img;
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    res[i][j] = meanSide(img, i, j, m, n);
                else
                    res[i][j] = meanNormal(img, i, j);
            }
        }
        return res;
    }
};
