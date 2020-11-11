#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define PLUS    '+'
#define MINUS   '-'
#define LP      '('
#define RP      ')'
#define SPACE   ' '

#define IS_NUM(c)               ((c) <= '9' && (c) >= '0')
#define TO_NUM(c)               ((c) - '0')
#define SKIP_SPACE(s, pos)      \
    do {                        \
        while((s)[pos] == ' ')  \
            (pos)++;            \
    } while(0)

static inline int parse_num(const string &s, int &i) {
    int res = 0;

    while(IS_NUM(s[i])) {
        res = res * 10 + TO_NUM(s[i]);
        i++;
    }
    return res;
}

class Solution {
public:
    int calculate(string s) {
        int pos = 0;
        return eval(pos, s);
    }

    int eval(int &pos, const string &s) {
        int res = 0;

        while(pos < s.size()) {
            switch(s[pos]) {
            case LP: 
            case '1':case '2': case '3':
            case '4':case '5':case '6':case '7': 
            case '8': case '9':case '0':
                res = parse_value(pos, s);
                break;
            case PLUS:
                ++pos;
                SKIP_SPACE(s, pos);
                res += parse_value(pos, s);
                break;
            case MINUS:
                ++pos;
                SKIP_SPACE(s, pos);
                res -= parse_value(pos, s);
                break;
            case RP:
                return res;
            case SPACE:
                SKIP_SPACE(s, pos);
                break;
            default:
                cout << "Unexpected character " << s[pos] << endl;
                exit(-1);
            }
        }
        return res;
    }

    int parse_value(int &pos, const string &s) {
        int res;
        if (IS_NUM(s[pos]))
            return parse_num(s, pos); 
        else if (s[pos] == LP) {
            res = eval(++pos, s);
            if (s[pos] != RP)
                cout << "Unmatched parenthese" << endl;
            ++pos;
            return res;
        }
        else
            cout << "Unexpected character " << s[pos] << endl;
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    ifstream in;
    
    char data[1024 * 1024];

    in.open("input.txt", ios::in);
    in >> data;
    
    int pos = 0;
    cout << parse_num(string("2147483647"), pos) << endl;
    /* cout << "answer is: " << s.calculate(string(data)) << endl; */
    in.close();
}
