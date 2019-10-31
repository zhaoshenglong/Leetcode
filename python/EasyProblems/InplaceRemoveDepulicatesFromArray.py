from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i: int = 0
        try:
            while i < nums.__len__():
                prev: int = nums[i]
                j: int = i + 1
                while nums[j] == prev:
                    nums.__delitem__(j)
                i += 1
        except IndexError:
            return nums.__len__()


def main():
    s: Solution = Solution()
    a = [0, 0, 1, 1, 2, 2, 3]
    s.removeDuplicates(a)
    print(a)


if __name__ == '__main__':
    main()
