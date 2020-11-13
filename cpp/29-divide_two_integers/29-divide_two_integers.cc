#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = false;
        long *res;
        long l_dividend = (long)dividend;
        long l_divisor = (long)divisor;
        long quotient;

        if ((l_dividend < 0 && l_divisor > 0) ||
                (l_dividend > 0 && l_divisor < 0))
            is_negative = true;
        l_dividend = l_dividend < 0 ? -l_dividend : l_dividend;
        l_divisor = l_divisor < 0 ? -l_divisor : l_divisor;
        
        res = l_divide(l_dividend, l_divisor);
        quotient = res[0];
        delete []res;

        if (quotient > INT_MAX && !is_negative)
            return INT_MAX;
        if (is_negative)
            return -quotient;
        else
            return quotient;

    }

    long *l_divide(long dividend, long divisor) {
        long *res;
        long *half;

        if (dividend < divisor) {
            /* cout << "dividend = " << dividend << "divisor = " << divisor << endl; */
            res = new long[2];
            res[0] = 0;
            res[1] = dividend;    
            return res;
        }

        half = l_divide(dividend >> 1, divisor);
        half[0] <<= 1;
        half[1] <<= 1;
        if (dividend & 1)
            half[1] += 1;
        if (half[1] >= divisor) {
            half[0] += 1;
            half[1] -= divisor;
        }
        return half;
    }
};

int main(int argc, char *argv[]) {
    int dividend, divisor;
    Solution s;

    if (argc < 3) {
        printf("Usage: %s <dividend> <divisor>\n", argv[0]);
        exit(0);
    }

    dividend = atoi(argv[1]);
    divisor = atoi(argv[2]);
    cout << s.divide(dividend, divisor) << endl;
    return 0;
}
