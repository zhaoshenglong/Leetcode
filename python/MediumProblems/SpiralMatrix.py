from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        h = len(matrix)
        if h == 0:
            return []
        if h == 1:
            return matrix[0]
        w = len(matrix[0])
        # if w == 1:
        #     for i in range(h):
        #         res.append(matrix[i][0])
        #     return res
        for b in range(min(h >> 1, w >> 1)):
            res.extend(matrix[b][b: w - b])
            for j in range(b + 1, h - b):
                res.append(matrix[j][w - b - 1])
            for i in range(w - b - 2, b - 1, -1):
                res.append(matrix[h - b - 1][i])
            for j in range(h - b - 2, b, -1):
                res.append(matrix[j][b])
        if h & 1 == 1 and w >= h:
            res.extend(matrix[h >> 1][h >> 1:w - (h >> 1)])
        if w & 1 == 1 and h > w:
            for j in range(w >> 1, h - (w >> 1)):
                res.append(matrix[j][w >> 1])
        return res


def main():
    s = Solution()
    print(s.spiralOrder(
        [
            [1, 2, 3]
        ]
    ))


if __name__ == '__main__':
    main()
