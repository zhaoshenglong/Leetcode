#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <set>

using namespace std;

#define CH_TO_INDEX(c)          ((c) - 'a')
#define TRIE_NR_CHILD           26
#define MARK_ACCESSED(c)        ((c) = (c) - 'a')
#define ACCESSED(c)             ((c) < 'a' ? true : false)
#define UNMARK(c)               ((c) = (c) + 'a')
#define UNMARKED_CHAR(c)        ((c) + 'a')

class TrieNode {
public:
    TrieNode(char ch, bool end) {
        int i;

        this->ch = ch;
        this->end = end;
        for(i = 0; i < TRIE_NR_CHILD; i++)
            this->children[i] = nullptr;
    }

    ~TrieNode() {
        int i;

        for (i = 0; i < TRIE_NR_CHILD; i++)
            if (this->children[i])
                delete (this->children[i]);
    }

    bool is_end() {
        return this->end;
    }

    char get_char() {
        return this->ch;
    }
    
    void set_end(bool end) {
        this->end = end;
    }

    TrieNode *insert(char ch, bool end) {
        if (!this->children[CH_TO_INDEX(ch)])
            this->children[CH_TO_INDEX(ch)] = new TrieNode(ch, end);
        else
            if (end)
                this->children[CH_TO_INDEX(ch)]->set_end(end);
        return this->children[CH_TO_INDEX(ch)];
    }

    TrieNode *get_child(char ch) {
        return this->children[CH_TO_INDEX(ch)];
    }
private:
    char ch;
    bool end;
    TrieNode *children[TRIE_NR_CHILD];
};

class Trie {
public:
    Trie() {
        _root = new TrieNode(' ', false);
    }

    ~Trie() {
        if (_root)
            delete _root;
    }

    void insert(string word) {
        int sz = word.size();
        int i;
        TrieNode *parent = this->_root;

        for (i = 0; i < sz - 1; i ++)
            parent = parent->insert(word[i], false);
        parent->insert(word[sz - 1], true);
    }

    // unused in this problem
    TrieNode *search(string word) {
        int sz = word.size();
        int i;
        TrieNode *res = nullptr;
        TrieNode *p = this->_root;
        
        for (i = 0; i < sz; i++) {
            p = p->get_child(word[i]);
            if (!p)
                return nullptr;
        }
        res = p;
        return res;
    }
    
    TrieNode *get_root() {
        return this->_root;
    }
private:
    TrieNode *_root;
};

void recursive_search(vector<vector<char>> &board, int i, int j, TrieNode *parent, string word, set<string> &res) {
    TrieNode *ptr;
    int width = board[0].size(), height = board.size();

    MARK_ACCESSED(board[i][j]);
    if (i - 1 >= 0 && !ACCESSED(board[i - 1][j])) {
        ptr = parent->get_child(board[i - 1][j]);
        if (ptr) {
            if (ptr->is_end())
                res.insert(word + board[i - 1][j]);
            recursive_search(board, i - 1, j, ptr, word + board[i - 1][j], res);
        }
    }
    if (i + 1 < height && !ACCESSED(board[i + 1][j])) {
        ptr = parent->get_child(board[i + 1][j]);
        if (ptr) {
            if (ptr->is_end())
                res.insert(word + board[i + 1][j]);
            recursive_search(board, i + 1, j, ptr, word + board[i + 1][j], res);
        }
    }
    if (j - 1 >= 0 && !ACCESSED(board[i][j - 1])) {
        ptr = parent->get_child(board[i][j - 1]);
        if (ptr) {
            if (ptr->is_end())
                res.insert(word + board[i][j - 1]);
            recursive_search(board, i, j - 1, ptr, word + board[i][j - 1], res);
        }
    }
    if (j + 1 < width && !ACCESSED(board[i][j + 1])) {
        ptr = parent->get_child(board[i][j + 1]);
        if (ptr) {
            if (ptr->is_end())
                res.insert(word + board[i][j + 1]);
            recursive_search(board, i, j + 1, ptr, word + board[i][j + 1], res);
        }
    }
    UNMARK(board[i][j]);
};

// helper function for printing trie, only for debug use
void print_trie(Trie *trie) {
    int i;
    pair<int, TrieNode *>p;
    list<pair<int, TrieNode *>> queue;
    int level = 1;

    queue.push_back(make_pair(0, trie->get_root()));
    
    while(!queue.empty()) {
        p = queue.front();
        queue.pop_front();
        if (p.first > level) {
            cout << endl;
            level++;
        }
        cout << p.second->get_char() << " ";
        for(i = 0; i < TRIE_NR_CHILD; i++) {
            if(p.second->get_child(i + 'a')) {
                queue.push_back(make_pair(p.first + 1, p.second->get_child(i + 'a')));
            } 
        }
    }

}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> res;
        Trie *trie;
        TrieNode *p;
        int i, j;
        int width, height;
        
        if (board.size() <= 0)
            return vector<string>();
        trie = this->build_trie(words);
        /* print_trie(trie); */
        width = board[0].size();
        height = board.size();

        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                p = trie->get_root()->get_child(board[i][j]);
                if (!p)
                    continue;
                else {
                    if (p->is_end())
                        res.insert(string(1, board[i][j]));
                    recursive_search(board, i, j, p, string(1, board[i][j]), res);
                }
            }
        }
        
        delete trie;
        return vector<string>(res.begin(), res.end());
    }
    
    Trie *build_trie(vector<string> &words) {
        Trie *trie;

        trie = new Trie();
        for (auto w : words)
            trie->insert(w);
        return trie;
    }
};


int main() {
    Solution s;
    vector<vector<char>> board = {{'a', 'a'}};//{{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> words = {"a"};//{"oath","pea","eat","rain"};
    vector<string> res;

    res = s.findWords(board, words);
    for (auto w: res)
        cout<< w << " ";
    cout << endl;
    return 0;
}

