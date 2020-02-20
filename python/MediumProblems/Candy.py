from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0
        sz = len(ratings)
        res = [1]
        decrease = True
        need_add = False
        add_start = 0
        for i in range(1, sz):
            if ratings[i] >= ratings[i - 1]:
                if ratings[i] == ratings[i - 1]:
                    res.append(1)
                else:
                    if res[i - 1] < 1:
                        res.append(2)
                    else:
                        res.append(res[i - 1] + 1)
                if need_add:
                    for j in range(add_start, i):
                        res[j] += (1 - res[i - 1])
                    if add_start > 0 and \
                            ratings[add_start - 1] > ratings[add_start] and \
                            res[add_start] >= res[add_start - 1]:
                        res[add_start - 1] = 1 + res[add_start]
                    need_add = False
                decrease = False
            else:
                if not decrease:
                    decrease = True
                    if ratings[i - 2] == ratings[i - 1]:
                        add_start = i - 1
                    else:
                        add_start = i
                if res[i - 1] > 1:
                    res.append(1)
                else:
                    need_add = True
                    res.append(res[i - 1] - 1)
        if need_add:
            for j in range(add_start, sz):
                res[j] += (1 - res[-1])
            print(res, need_add)
            if add_start > 0 and \
                    ratings[add_start - 1] > ratings[add_start] and \
                    res[add_start] >= res[add_start - 1]:
                res[add_start - 1] = 1 + res[add_start]
                print(res)
        print(res)
        return sum(res)


def main():
    s = Solution()
    print(s.candy([1, 3, 2, 2, 1]))


if __name__ == '__main__':
    main()
