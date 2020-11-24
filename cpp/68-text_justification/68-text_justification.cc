#include <iostream>
#include <vector>
#include <string>
#include "../include/print_x.hpp"

using namespace std;

static inline string format_line(vector<string>& words, int start, int end, int curwidth, int maxwidth, bool is_lastline) {
    string res = "";
    int exsp = maxwidth - curwidth;
    int slot = end - start;
    string last_word;
    int i;

    if (is_lastline)
        last_word = words[end] + string(exsp, ' ');
    else
        last_word = words[end];
    // excluede the last word
    for (i = 0; i < (end - start); i++) {
        res += words[start + i];
        res += " ";
        if (!is_lastline) {
            if (exsp / slot > 0)
                res += string(exsp / slot, ' ');
            if (i < exsp - exsp / slot * slot)
                res += " ";
        } 
    }
    res += last_word;
    if (end == start && (int)last_word.size() < maxwidth)
        res += string(maxwidth - last_word.size(), ' ');
    return res;
}

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i;
        int sz = words.size();
        int curwidth;
        vector<string> res;
        string s;
        int start;

        i = 0;
        curwidth = 0;
        while (i < sz) {
            if (curwidth == 0) {
                start = i;
                curwidth += words[i].size();
            } else {
                // time to format a line
                if (curwidth + (int)words[i].size() + 1 > maxWidth) {
                    res .push_back(format_line(words, start, i - 1, curwidth, maxWidth, false));
                    curwidth = words[i].size();
                    start = i;
                } else {
                    curwidth += 1 + words[i].size();
                }
            }
            i++;
        }
        // format last line
        if (curwidth != 0) {
            res.push_back(format_line(words, start, sz - 1, curwidth, maxWidth, true));
        }
        return res;
    }
};

void initial(vector<string>& words) {
    words.push_back(string("This"));
    words.push_back(string("is"));
    words.push_back(string("an"));
    words.push_back(string("example"));
    words.push_back(string("of"));
    words.push_back(string("text"));
    words.push_back(string("justification."));
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<string> words;
    int maxWidth = 16;
    
    initial(words);
    cout << s.fullJustify(words, maxWidth) << endl;
    return 0;
}
