#include "../../include/leetcode.hpp"

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1 = 0, r2 = 0, v1 = 0, v2 = 0; 
        
        r1 = strtol(num1.data(), nullptr, 10);
        r2 = strtol(num2.data(), nullptr, 10);
        v1 = strtol(num1.substr(num1.find('+') + 1).data(), nullptr, 10);
        v2 = strtol(num2.substr(num1.find('+') + 1).data(), nullptr, 10);
        cout << r1 << v1 << r2 << v2 << endl;
        return to_string(r1*r2 - v1*v2) + "+" + to_string(r1*v1 + r2*v1) + "i";
    }
};

int main() {
    auto solution = Solution();
    
    cout << solution.complexNumberMultiply("1+-1i", "1+-1i");
}
