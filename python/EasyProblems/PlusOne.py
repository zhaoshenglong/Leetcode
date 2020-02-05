from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        digits[i] += 1
        while digits[i] >= 10:
            digits[i] -= 10
            i -= 1
            if i >= 0:
                digits[i] += 1
            else:
                if digits[0] == 0:
                    res = [1]
                    res.extend(digits)
                    return res
        return digits


def main():
    s = Solution()
    print(s.plusOne([9, 9, 9]))


if __name__ == '__main__':
    main()
