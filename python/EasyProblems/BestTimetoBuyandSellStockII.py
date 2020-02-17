from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        profit = 0
        max_price = prices[0]
        min_price = prices[0]
        for i in range(1, len(prices)):
            t = prices[i]
            if t < max_price:
                profit += max_price - min_price
                min_price = t
                max_price = t
            else:
                max_price = t
        return profit + max_price - min_price


def main():
    s = Solution()
    print(s.maxProfit([1, 2, 3, 4, 5]))


if __name__ == '__main__':
    main()
