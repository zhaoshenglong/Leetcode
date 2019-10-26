from typing import List, Dict


class Solution:
    def two_sum(self, nums: List[int], target: int) -> List[int]:
        hash_nums: Dict[int, int] = {}
        for i in range(nums.__len__()):
            remain: int = target - nums[i]
            if hash_nums.__contains__(remain):
                return [hash_nums[remain], i]
            else:
                hash_nums[nums[i]] = i
        raise LookupError


def main():
    s: Solution = Solution()
    print(s.two_sum([2, 7, 11, 15], 9))


if __name__ == "__main__":
    main()
