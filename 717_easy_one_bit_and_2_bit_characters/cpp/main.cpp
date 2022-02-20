#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        auto len    = bits.size();
        int  i      = 0;

        if (bits[len - 1] == 1)
            return false;

        while(i < len - 1) {
            if (bits[i] == 0)
                i += 1;
            else
                i += 2;
        }
        return i < len;
    }

};

int main(int argc, char **argv) {
    auto s = new Solution();
    auto bits = vector<int>({1,0,1});
    cout << s->isOneBitCharacter(bits) << endl;
    delete s;
    return 0;
}
