#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../include/print_x.hpp"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int w_i;                        
        int w_sz = words[0].size();
        int s_sz = s.size();
        vector<int> pos;                // store word's position of occurence in s
        map<int, int> posseq;           // temporarily store pos sequence
        int seqcnt = 0;
        vector<int> res;
        bool found = false;
        int i, j;
        map<string, int> wordcnt;

        build_map(wordcnt, words);
        for (w_i = 0; w_i < w_sz; w_i++) {
            j = w_i;
            pos.clear();
            while (j + w_sz <= s_sz) {
                found = false;
                for (i = 0; i < words.size(); i++) {
                    if (!s.compare(j, w_sz, words[i])) {
                        pos.push_back(i);
                        found = true;
                        break;
                    }    
                }
                if (!found)
                    pos.push_back(-1);
                j += w_sz;
            }

            // search in the pos vector to evaluate if there exists a sequence of 
            // concatenation words

            seqcnt = 0;
            posseq.clear();
            for (i = 0; i < pos.size(); i++) {
                if (pos[i] == -1) {
                    seqcnt = 0;
                    posseq.clear();
                    continue;
                }
                if (posseq.find(pos[i]) == posseq.end()) {
                    posseq[pos[i]] = 1;
                    seqcnt++;
                    if (seqcnt == words.size()) {
                        res.push_back((i - words.size() + 1) * w_sz + w_i);
                        posseq[pos[i - words.size() + 1]] --;
                        if (posseq[pos[i - words.size() + 1]] == 0) {
                            posseq.erase(pos[i - words.size() + 1]);
                        }
                        seqcnt--;
                    }
                } else {
                    if (posseq[pos[i]] < wordcnt[words[pos[i]]]) {
                        posseq[pos[i]]++;
                        seqcnt++;
                        if (seqcnt == words.size()) {
                            res.push_back((i - words.size() + 1 ) * w_sz + w_i);
                            posseq[pos[i - words.size() + 1]] --;
                            if (posseq[pos[i - words.size() + 1]] == 0) {
                                posseq.erase(pos[i - words.size() + 1]);
                            }
                            seqcnt--;
                        }
                    } else {
                        posseq.clear();
                        seqcnt = 0;
                        for (j = i; j >= 0; j--) {
                            if (pos[j] == -1)
                                break;
                            if (pos[j] == pos[i] && posseq[pos[j]] >= wordcnt[words[pos[j]]])
                                break;
                            if (posseq.find(pos[j]) == posseq.end())
                                posseq[pos[j]] = 1;
                            else
                                posseq[pos[j]] ++;
                            seqcnt++;
                        }
                    }
                }
            } 
        }
        return res;            
    }
    
    void build_map(map<string, int>& wcnt, vector<string>& words) {
        for (string w: words) {
            if (wcnt.find(w) == wcnt.end()) {
                wcnt[w] = 1;
            } else {
                wcnt[w] ++;
            }
        }
    }
};
int main(int argc, char *argv[]) {
    Solution s;
    string str("aaaaaaaaaaaaaa");
    string warr[] = {"aa", "aa"};
    vector<string> words(warr, warr + 2);

    cout << s.findSubstring(str, words) << endl;
    return 0;
}
