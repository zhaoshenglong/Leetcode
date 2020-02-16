from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        else:
            res = [[1], [1, 1]]
            for i in range(2, numRows):
                r = [1]
                prev = res[i - 1]
                for j in range(len(prev) - 1):
                    r.append(prev[j] + prev[j + 1])
                r.append(1)
                res.append(r)
            return res


def main():
    s = Solution()
    print(s.generate(5))


if __name__ == '__main__':
    main()
