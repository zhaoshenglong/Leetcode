#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include "../include/print_x.hpp"

#define MAXSZ           1000000
#define NRLETTER        52

#define LETTER_TO_IDX(c)    ((c) >= 'a' ? (c) + 26 - 'a' : (c) - 'A')

using namespace std;

static inline int get_win_st(map<int, list<int>>const & occ) {
    int res = MAXSZ;
    for (auto e: occ)
        if (e.second.front() < res)
            res = e.second.front();
    return res;
                
}

class Solution {
public:
    string minWindow(string s, string t) {
        int freq[NRLETTER];             // record character frequency in t
        int occ[NRLETTER];              // record character occurence from t in s
        map<int, list<int>> all_occ;    // record all of occurence position of characters from t in s
        set<int> occ_pos;             // first occurence of each character from t in s
        int minsz = MAXSZ;              // record minimum size of window
        int win_st, min_st;             // window start position
        int occ_cnt = 0;                // count character occurence of t in s
        int idx;                        // LETTER_TO_IDX
        int s_sz = s.size(), t_sz = t.size();
        int i;
        
        // initial
        for (i = 0; i < NRLETTER; i++)
            freq[i] = occ[i] = 0;

        // count frequency
        for (char c: t) {
            freq[LETTER_TO_IDX(c)]++;
        }
        
        for(i = 0; i < s_sz; i++) {
            idx = LETTER_TO_IDX(s[i]);
            if (freq[idx] > 0) {
                all_occ[idx].push_back(i);
                if (occ[idx] < freq[idx]) {
                    occ[idx]++;
                    occ_pos.insert(i);
                    occ_cnt ++;
                } else {
                    occ_pos.erase(all_occ[idx].front());
                    all_occ[idx].pop_front();
                    occ_pos.insert(i);
                }

                if (occ_cnt == t_sz) {
                    win_st = *(occ_pos.begin()); 
                    minsz = i - win_st + 1;
                    min_st = win_st;
                    cout << "i " << i <<" win_st "<< win_st << " minsz " << minsz << " " << s.substr(min_st, minsz) << endl;
                    break;
                }
            }
        }

        cout << "i " << i << endl;
        cout << occ_pos << endl;
        for (i = i + 1; i < s_sz; i++) {
            idx = LETTER_TO_IDX(s[i]);
            if (freq[idx] > 0) {
                all_occ[idx].push_back(i);
                occ_pos.erase(all_occ[idx].front());
                all_occ[idx].pop_front();
                occ_pos.insert(i);
                
                win_st = *(occ_pos.begin()); 
                cout << "set" << endl;
                cout << occ_pos << endl;
                cout << "win_st " << win_st << endl;
                if (win_st != min_st && i - win_st + 1 < minsz) {
                    minsz = i - win_st + 1;
                    min_st = win_st;
                }
            }
        }

        if (minsz == MAXSZ)
            return "";
        else
            return s.substr(min_st, minsz);
    }
};

int main(int argc, char *argv[]) {
    string s("aaflslflsldkalskaaa");
    string t("aaa");
    Solution sol;

    cout << sol.minWindow(s, t) << endl;
    return 0;
}
