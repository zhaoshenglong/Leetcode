from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sz = len(intervals)
        if sz == 0 or sz == 1:
            return intervals
        res = []
        intervals.sort(key=lambda e: e[0])
        t = intervals[0]
        for e in intervals[1:]:
            if t[1] >= e[0]:
                if t[1] < e[1]:
                    t[1] = e[1]
            else:
                res.append(t)
                t = e.copy()
        res.append(t)
        return res


def main():
    s = Solution()
    print(s.merge([[1, 3], [4, 6], [5, 7], [8, 15]]))


if __name__ == '__main__':
    main()
