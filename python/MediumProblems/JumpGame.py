from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        sz = len(nums)
        if sz == 1:
            return True
        target = sz - 1
        i = target - 1
        while i != 0:
            if i + nums[i] >= target:
                target = i
            i -= 1
        if nums[i] >= target:
            return True
        else:
            return False


def main():
    s = Solution()
    print(s.canJump([3, 2, 1, 1, 4]))


if __name__ == '__main__':
    main()
