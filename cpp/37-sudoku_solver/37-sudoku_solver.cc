#include <iostream>
#include <vector>
#include "../include/print_x.hpp"
#include <set>

using namespace std;

#define EMPTY               '.'
#define INSERT_MODE         255
#define REMOVE_MODE         256

#define IS_EMPTY(c)         ((c) == '.')
#define INT_TO_CHAR(i)      ((char)((i) + '0'))

static inline vector<vector<set<char>>>
update_table(char ch, int i, int j, vector<vector<set<char>>> &bd_table) {
    int m, n;
    vector<vector<set<char>>> saved_table(bd_table);

    for (m = 0; m < 9; m++) {
        bd_table[i][m].erase(ch);
        bd_table[m][j].erase(ch);
    }
    for (m = 0; m < 3; m++) {
        for (n = 0; n < 3; n++) {
            bd_table[i / 3 * 3 + m][j / 3 * 3 + n].erase(ch);
        }
    }
    /* if (i == 0){ */
    /*     cout << "i = " << i << "j = " << j << endl; */
    /*     cout << "saved_table: " << endl; */
    /*     cout << saved_table[0] << endl; */
    /*     cout << "bd_table:" << endl; */
    /*     cout << bd_table[0] << endl; */
    /* } */
    return saved_table;
}

void build_table(vector<vector<char> > &board, vector<vector<set<char>>> &bd_table) {
    int i, j;
    static set<char> digits;
    vector<set<char>> bd_row;
    
    if (digits.size() < 9) {
        for (i = 1; i <= 9; i++)
            digits.insert(INT_TO_CHAR(i));
    }

    for (i = 0; i < 9; i++) {
        bd_row = vector<set<char>>();
        bd_table.push_back(bd_row);
        for (j = 0; j < 9; j++)
            bd_table[i].push_back(set<char>(digits));        
    }
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (!IS_EMPTY(board[i][j]))
                update_table(board[i][j], i, j, bd_table);
        }
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>> bd_table;
        build_table(board, bd_table);         
        do_solve(board, 0, 0, bd_table); 
    }

    bool do_solve(vector<vector<char>> &board, int row_st, int col_st, vector<vector<set<char>>> &bd_table) {
        int i, j;
        set<char> chs;
        vector<vector<set<char>>> saved_table;

        if (col_st == 9) {
            i = row_st + 1;
            j = 0;
        } else {
            i = row_st;
            j = col_st;
        }

        for (; i < 9; i++) {
            while(j < 9) {
                if (IS_EMPTY(board[i][j])) {
                    chs = set<char>(bd_table[i][j]);

                    for (char ch: chs) {
                        board[i][j] = ch;
                        saved_table = update_table(ch, i, j, bd_table);
                        if(do_solve(board, i, j + 1, bd_table))
                            return true;
                        bd_table = saved_table;
                        board[i][j] = EMPTY;
                    }
                    return false;
                }
                j++;
            }
            j = 0;
        }
        return true;
    }
};

void init_board(vector<vector<char>>& board, const char **arr) {
    int i, j;
    vector<char> row;

    for (i = 0; i < 9; i++) {
        row = vector<char>();
        for (j = 0; j < 9; j++) {
            row.push_back(arr[i][j]);
            
        }
        board.push_back(row);
    }
}

int main(int argc, char **argv) {
    const char *board_arr[9] = {                    
        "53..7....",  
        "6..195...",  
        ".98....6.",  
        "8...6...3",  
        "4..8.3..1",  
        "7...2...6",  
        ".6....28.",  
        "...419..5",  
        "....8..79"   
    };
    vector<vector<char> > board;
    Solution s;

    init_board(board, board_arr);
    s.solveSudoku(board);
    cout << board << endl;
    return 0;
}
