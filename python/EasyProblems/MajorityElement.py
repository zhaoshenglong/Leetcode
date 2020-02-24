from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        sz = len(nums)
        i = 0
        while i < sz:
            candidate = nums[i]
            cnt = 1
            j = i + 1
            while cnt > 0 and j < sz:
                if nums[j] == candidate:
                    cnt += 1
                else:
                    cnt -= 1
                j += 1
            if j == sz:
                # 题意指出必定有一解，因此遍历所有的数必然是解
                return candidate
            else:
                i = j


def main():
    s = Solution()
    print(s.majorityElement([2, 2, 1, 1, 1]))


if __name__ == '__main__':
    main()
