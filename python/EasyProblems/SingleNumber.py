from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            res ^= i
        return res


def main():
    s = Solution()
    print(s.singleNumber([2, 2, 1]))


if __name__ == '__main__':
    main()
