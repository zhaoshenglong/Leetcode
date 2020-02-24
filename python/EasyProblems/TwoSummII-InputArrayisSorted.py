from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i in range(len(numbers)):
            t = target - numbers[i]
            if nums_dict.get(t) is not None:
                return [nums_dict[t], i + 1]
            else:
                nums_dict[numbers[i]] = i + 1


def main():
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 9))


if __name__ == '__main__':
    main()
