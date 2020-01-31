from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        cnt = 0
        for t in nums:
            if t < target:
                cnt += 1
            else:
                return cnt
        if cnt == len(nums) - 1:
            return cnt + 1
        return cnt


def main():
    s: Solution = Solution()
    print(s.searchInsert([1,3,5,6], 5))


if __name__ == '__main__':
    main()
