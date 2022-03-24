#include "../../include/leetcode.hpp"

class Solution {

public:
    int calculate(string s) {
        auto iss = istringstream(s);
        return eval(iss);
    }

    int eval(istringstream& iss) {
        char c;
        int res = 0;
        int val;
        queue<char> operators;
        
        while(!iss.eof()) {
            c = iss.get();
            if (isdigit(c)) {
                iss.unget();
                iss >> val;
                if (operators.empty()) {
                    res = val;
                    continue;
                }
                char op = operators.front();
                if (op == '+')
                    res += val;
                else
                    res -= val;
            } else if (c == '+' || c == '-') {
                operators.push(c);
            } else if (c == '(') {
                val = eval(iss);
                if (operators.empty()) {
                    res = val;
                    continue;
                }
                char op = operators.front();
                if (op == '+')
                    res += val;
                else
                    res -= val;
            } else if (c == ')') {
                return res;
            } else {
                continue;
            }
        }
        return res;
    }
};

