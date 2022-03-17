#include "../../include/leetcode.hpp"

class Solution {
public:
    string longestWord(vector<string>& words) {
        map<string, set<string>> wordSucc;
        set<string> startStrs;

        for (auto& w: words) {
            if (w.size() == 1) {
                startStrs.insert(w);
            }
            wordSucc[w] = {};
        }

        for (auto& w: words) {
            if (wordSucc.find(w.substr(0, w.size() - 1)) != wordSucc.end()) {
                wordSucc[w.substr(0, w.size() - 1)].insert(w);
            }
        }

        fmt::print("{}\n", wordSucc);
        fmt::print("{}\n", startStrs);

        int maxSize = 0;
        string res = "";
        queue<string> wordQueue;
        for (auto &start: startStrs) {
            wordQueue.push(start);
            while(!wordQueue.empty()) {
                string s = wordQueue.front();
                wordQueue.pop();
                if (wordSucc[s].empty() && s.size() > maxSize) {
                    maxSize = s.size();
                    res = s;
                }
                for (auto& w: wordSucc[s]) {
                    wordQueue.push(w);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto strs = vector<string>({"w","wo","wor","worl","world"});
    cout << sol.longestWord(strs) << endl;
}
