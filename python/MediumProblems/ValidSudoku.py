from typing import List


EMPTY = "."


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        r = [{}, {}, {}]
        c = [{}, {}, {}, {}, {},
             {}, {}, {}, {}]
        b = {}
        for bi in range(3):
            for bj in range(3):
                for i in range(3):
                    for j in range(3):
                        t = board[bi * 3 + i][bj * 3 + j]
                        if t != EMPTY:
                            if b.get(t) is not None or \
                                    r[i].get(t) is not None or \
                                    c[bj * 3 + j].get(t) is not None:
                                return False
                            b[t] = t
                            r[i][t] = t
                            c[bj * 3 + j][t] = t
                b.clear()
            r[0].clear()
            r[1].clear()
            r[2].clear()
        return True


def main():
    s = Solution()
    board = [
      ["8","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]
    print(s.isValidSudoku(board))


if __name__ == '__main__':
    main()
