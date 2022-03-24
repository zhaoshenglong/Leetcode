#include "../../include/leetcode.hpp"
class Solution {
    int pos = 0;

    bool isoperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/'; 
    }

    int priority(char c) {
        if (c == '+' || c == '-')
            return 0;
        if (c == '*' || c == '/')
            return 1;
        return -1;
    }

    int parseInt(const string& s) {
        int val = 0;
        int len = s.size();

        while(pos < len && isdigit(s[pos])) {
            val *= 10;
            val += s[pos] - '0';
            pos++; 
        }
        if (pos < len)
            pos--;
        return val;
    }
    
    int eval(const string& s) {
        int len = s.size();
        stack<int> operators({'+'});
        stack<int> operands({0});
        int val;

        while (pos < len) {
            // cout << "s[pos] " << (char)s[pos] << endl;
            if (isdigit(s[pos])) {
                val = parseInt(s);
                operands.push(val);
            } else if (isoperator(s[pos])) {
                char op = operators.top();
                while (priority(op) >= priority(s[pos])) {
                    int right = operands.top();
                    operands.pop();
                    int left = operands.top();
                    operands.pop();
                    operators.pop();
                    // cout << " compute " << left << op << right << endl;
                    operands.push(compute(left, right, op));
                    if (operators.empty())
                        break;
                    op = operators.top();
                }
                operators.push(s[pos]);
            }
            pos++;
        }
        while(!operators.empty()) {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();
            operands.push(compute(left, right, operators.top()));
            // cout << " compute " << left << " " << (char)operators.top() << " " << right << endl;
            operators.pop();
        }
        return operands.top();
    }

    int compute(int a, int b, char op) {
        switch(op){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }

public:
    int calculate(string s) {
        return eval(s);
    }
};
