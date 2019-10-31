from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i: int = 0
        l: int = nums.__len__()
        while i < l:
            if nums[i] == val:
                nums.__delitem__(i)
                l -= 1
            else:
                i += 1
        return i


def main():
    s: Solution = Solution()
    a = [1, 2, 2, 3, 4, 5, 6]
    print(s.removeElement(a, 2))
    print(a)


if __name__ == '__main__':
    main()