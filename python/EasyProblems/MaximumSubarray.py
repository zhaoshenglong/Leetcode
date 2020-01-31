from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        res = nums[0]
        tmp = 0
        for i in nums:
            tmp += i
            if tmp > res:
                res = tmp
            if tmp <= 0:
                tmp = 0
        return res


def main():
    s = Solution()
    print(s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))


if __name__ == '__main__':
    main()
