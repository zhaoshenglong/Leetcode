#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long base = 10;
        long res = 0;
        
        if (n <= 0)
            return 0;
        while (n >= base) {
            res += res * 9 + base / 10;
            base *= 10;
        }
        if (n / (base / 10) > 1)
            res += res * (n / (base / 10) - 1);
        
        if (n >= base / 10 * 2)
            res += base / 10;
        else
            res += n - base / 10 + 1;
        if (n % (base / 10) >= 1)
            return res + this->countDigitOne(n % (base / 10));
        else
            return res;
    }
};

int main(int argc, char **argv) {
    int n = 0;
    Solution s;

    if (argc < 2) {
        printf("Usage: %s [number]\n", argv[0]);
        exit(0);
    }
    
    n = atoi(argv[1]);
    cout << "n = " << n << endl;
    cout << s.countDigitOne(n) << endl;
}
