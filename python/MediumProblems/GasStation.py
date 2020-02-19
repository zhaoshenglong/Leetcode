from typing import List


def find_start(l, lo, hi):
    if hi - lo == 1:
        return lo, hi, l[lo]
    else:
        mid = (lo + hi) >> 1
        left = find_start(l, lo, mid)
        right = find_start(l, mid, hi)
        res = left if left[2] > right[2] else right

        s = right[2]
        max_sum = 0
        max_sum_idx = 0
        i = right[0] - 1
        while i >= left[0]:
            s += l[i]
            if s > max_sum:
                max_sum = s
                max_sum_idx = i
            i -= 1

        if res[2] < max_sum:
            return max_sum_idx, right[1], max_sum
        else:
            return res


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        minus_list = []
        sz = len(gas)
        for i in range(sz):
            minus_list.append(gas[i] - cost[i])
        if sum(minus_list) < 0:
            return -1
        minus_list.extend(minus_list)
        return find_start(minus_list, 0, sz << 1)[0] % sz


def main():
    s = Solution()
    print(s.canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]))
    # print(find_start([-1, 3, -4, 2, -1, 3, -4, 2], 0, 8))


if __name__ == '__main__':
    main()
