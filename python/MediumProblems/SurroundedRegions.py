from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        height = len(board)
        width = len(board[0])
        searched = {}
        for i in range(1, height - 1):
            for j in range(1, width - 1):
                if board[i][j] == "O" and searched.get((i, j)) is None:
                    q = [(i, j)]
                    sz = 1
                    k = 0
                    searched[(i, j)] = 1
                    is_region = True
                    while k < sz:
                        x, y = q[k]
                        k += 1
                        for d in [(x - 1, y), (x, y - 1), (x + 1, y), (x, y + 1)]:
                            if 0 <= d[0] < height and 0 <= d[1] < width \
                                    and board[d[0]][d[1]] == "O" \
                                    and searched.get(d) is None:
                                q.append(d)
                                sz += 1
                                searched[d] = 1
                                if d[0] == 0 or d[0] == height - 1 \
                                        or d[1] == 0 or d[1] == width - 1:
                                    is_region = False
                    if is_region:
                        for item in q:
                            board[item[0]][item[1]] = "X"


def main():
    s = Solution()
    a = [
        ["X", "X", "X", "X"],
        ["X", "O", "O", "X"],
        ["X", "O", "O", "X"],
        ["X", "O", "X", "X"]
    ]
    s.solve(a)
    print(a)


if __name__ == '__main__':
    main()
