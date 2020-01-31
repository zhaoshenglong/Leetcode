from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        m = {0: [[]]}
        for i in range(len(candidates)):
            t = candidates[i]
            cnt = 0
            r = target - t
            while t <= target:
                if m.get(t) is not None:
                    m[t].append([candidates[i] for _ in range(cnt + 1)])
                else:
                    m[t] = [[candidates[i] for _ in range(cnt + 1)]]
                t += candidates[i]
                cnt += 1
        for i in range(len(candidates)):
            t = candidates[i]
            r = target - t
            if m.get(r) is not None:
                for j in m.get(r):
                    l = list.copy(j)
                    l.append(candidates[i])
                    res.append(l)
        return res


def main():
    s = Solution()
    c = [2, 3, 5]
    t = 8
    print(s.combinationSum(c, t))


if __name__ == '__main__':
    main()
