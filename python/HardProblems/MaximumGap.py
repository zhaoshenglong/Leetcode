from typing import List


class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        sz = len(nums)
        if sz < 2:
            return 0

        # 先用基数排序进行排序
        nums_dict = {}

        j = 1
        already_sorted = False
        while not already_sorted:
            already_sorted = True
            for i in nums:
                t = int(i / j)
                if t > 0:
                    already_sorted = False
                key = t % 10
                if not nums_dict.get(key):
                    nums_dict[key] = [i]
                else:
                    nums_dict[key].append(i)
            nums = []
            for i in range(10):
                if nums_dict.get(i) is not None:
                    nums.extend(nums_dict[i])
                    nums_dict[i] = None
            j *= 10
        gap = 0
        for i in range(sz - 1):
            t = nums[i + 1] - nums[i]
            if t > gap:
                gap = t
        return gap


def main():
    s = Solution()
    print(s.maximumGap([100, 3, 2, 1]))


if __name__ == '__main__':
    main()
