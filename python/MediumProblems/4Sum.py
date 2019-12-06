from typing import List, Dict, Tuple, Set


class Solution:
    def four_sum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        index_set: Set[Tuple] = set()
        res_set: Set[Tuple] = set()

        history: Dict[int, List] = {}
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                s = nums[i] + nums[j]
                if history.get(target - s) is not None:
                    for t in history.get(target - s):
                        if t[0] != i and t[1] != i \
                                and t[0] != j and t[1] != j:
                            a = [t[0], t[1], i, j]
                            a.sort()
                            b = [nums[a[0]], nums[a[1]], nums[a[2]], nums[a[3]]]
                            b.sort()
                            if not res_set.issuperset({tuple(b)}):
                                index_set.add(tuple(a))
                                res_set.add(tuple(b))
                if history.get(s) is None:
                    history[s] = []
                history[s].append((i, j))
        res = []
        # print(res_set)
        for s in list(index_set):
            res.append([nums[s[0]], nums[s[1]], nums[s[2]], nums[s[3]]])
        return res


def main():
    s = Solution()
    a = [-3,-2,-1,0,0,1,2,3]
    print(s.four_sum(a, 0))


if __name__ == '__main__':
    main()
