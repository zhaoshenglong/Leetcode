from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        i = 1
        j = 1
        last = nums[0]
        while i < length:
            duplicate = nums[i] == last
            if i != j:
                nums[j] = nums[i]
            if duplicate:
                while i < length and nums[i] == last:
                    i += 1
            else:
                last = nums[i]
                i += 1
            j += 1
        return j


def main():
    s = Solution()
    print(s.removeDuplicates([0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 3]))


if __name__ == '__main__':
    main()
