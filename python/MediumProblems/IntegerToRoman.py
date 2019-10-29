class Solution:
    def int2roman(self, num:int) -> str:
        res: str = ""
        while num >= 1000:
            num -= 1000
            res += 'M'
        if num >= 900:
            num -= 900
            res += "CM"
        else:
            if num >= 500:
                num -= 500
                res += "D"
            if num >= 400:
                num -= 400
                res += "CD"
            while num >= 100:
                num -= 100
                res += "C"
        if num >= 90:
            num -= 90
            res += "XC"
        else:
            if num >= 50:
                num -= 50
                res += "L"
            if num >= 40:
                num -= 40
                res += "XL"
            while num >= 10:
                num -= 10
                res += "X"
        if num == 9:
            res += "IX"
        else:
            if num >= 5:
                num -= 5
                res += "V"
            if num >= 4:
                num -= 4
                res += "IV"
            while num >= 1:
                num -= 1
                res += "I"
        return res


def main():
    s: Solution = Solution()
    print(s.int2roman(1994))


if __name__ == "__main__":
    main()
