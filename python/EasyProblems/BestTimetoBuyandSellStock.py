from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sz = len(prices)
        if sz <= 1:
            return 0
        min_price = prices[0]
        max_price = prices[0]
        profit = 0
        for i in range(1, sz):
            if prices[i] < min_price:
                min_price = prices[i]
                max_price = prices[i]
            if prices[i] > max_price:
                max_price = prices[i]
            t = max_price - min_price
            if t > profit:
                profit = t
        return profit


def main():
    s = Solution()
    print(s.maxProfit([7, 1, 5, 3, 6, 4]))


if __name__ == '__main__':
    main()
