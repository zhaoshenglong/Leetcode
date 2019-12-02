from typing import List, Dict, Set


class Solution:
    def three_sum(self, nums: List[int]) -> List[List[int]]:
        res: Set[tuple] = set()

        for i in range(len(nums)):
            target = -nums[i]
            search_dict: Dict = {}
            for j in range(i + 1, len(nums)):
                remain = target - nums[j]
                if search_dict.get(remain) is not None:
                    if nums[i] < nums[j]:
                        if nums[j] < remain:
                            res.add((nums[i], nums[j], remain))
                        elif nums[i] < remain:
                            res.add((nums[i], remain, nums[j]))
                        else:
                            res.add((remain, nums[i], nums[j]))
                    else:
                        if nums[i] < remain:
                            res.add((nums[j], nums[i], remain))
                        elif nums[j] > remain:
                            res.add((remain, nums[j], nums[i]))
                        else:
                            res.add((nums[j], remain, nums[i]))
                else:
                    search_dict[nums[j]] = nums[j]
        return list(res)


def main():
    s = Solution()
    a = [-1, 0, 1, 2, -1, -4]
    print(s.three_sum(a))


if __name__ == '__main__':
    main()
