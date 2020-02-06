from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last_not_red = 0
        last_not_white = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                # 交换红色和最后一个不是红色的
                t = nums[last_not_red]
                nums[last_not_red] = nums[i]
                nums[i] = t
                last_not_red += 1
                if last_not_white > last_not_red - 1:
                    # 在红色后面有白色，把换到后面的白色再换到最后一个白色
                    t = nums[last_not_white]
                    nums[last_not_white] = nums[i]
                    nums[i] = t
                    last_not_white += 1
                else:
                    last_not_white = last_not_red
            elif nums[i] == 1:
                # 交换白色和最后一个不是白色的
                t = nums[last_not_white]
                nums[last_not_white] = nums[i]
                nums[i] = t
                last_not_white += 1


def main():
    s = Solution()
    a = [1, 0, 1]
    s.sortColors(a)
    print(a)


if __name__ == '__main__':
    main()

