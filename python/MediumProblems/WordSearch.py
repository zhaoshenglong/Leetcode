from typing import List, Dict


def search(board, m, n, word, k, cur, searched: Dict) -> bool:
    if k == len(word):
        return True
    else:
        for d in [(cur[0] - 1, cur[1]), (cur[0] + 1, cur[1]), (cur[0], cur[1] - 1), (cur[0], cur[1] + 1)]:
            if 0 <= d[0] < m and 0 <= d[1] < n \
                    and board[d[0]][d[1]] == word[k]\
                    and searched.get(d) is None:
                searched[d] = 1
                if search(board, m, n, word, k + 1, d, searched):
                    return True
                searched[d] = None
        return False


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    # 回溯搜索
                    if search(board, m, n, word, 1, (i, j), {(i, j): 1}):
                        return True
        return False


def main():
    s = Solution()
    print(s.exist([['a', 'a']], "aa"))


if __name__ == '__main__':
    main()
