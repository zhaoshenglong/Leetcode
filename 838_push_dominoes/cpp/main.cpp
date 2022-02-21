#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int len = dominoes.size();
        int R   = -1, L = -1;
        int i   = 0, k;

        while(i < len) {
            if (dominoes[i] == 'R') {
                if (R > L)
                    for (k = R; k < i; k++)
                        dominoes[k] = 'R';
                R = i;
            } 

            if (dominoes[i] == 'L') {
                if (R > L) {
                    for (k = 1; k <= (i - R - 1) / 2; k++) {
                        dominoes[R + k] = 'R';
                        dominoes[i - k] = 'L';
                    }
                } else {
                    for (k = L > 0 ? L : 0; k < i; k++)
                        dominoes[k] = 'L';
                }
                L = i;
            }
            i++;
        }

        if (R < len && R > L)
            for (i = R; i < len; i++)
                dominoes[i] = 'R';
        return dominoes;
    }
};

int main(int argc, char **argv) {
    string s = ".L.R...LR..L..";
    auto sol = Solution();
    cout << sol.pushDominoes(s) << endl;
    return 0;
}
