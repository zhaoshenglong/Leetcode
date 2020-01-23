class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        n1 = len(num1)
        n2 = len(num2)
        n = n1 + n2
        res = ['0' for i in range(n)]
        s = 0
        for i in range(n1 - 1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                r = (ord(num1[i]) - 48) * (ord(num2[j]) - 48)
                r += ord(res[n1 - s + j]) - 48
                res[n1 - s + j] = chr(r % 10 + 48)
                res[n1 - s + j - 1] = chr(int(r / 10) + ord(res[n1 - s + j - 1]))
            s += 1
        num = "".join(res)
        return num.lstrip("0")


def main():
    s = Solution()
    print(s.multiply("123", "456"))


if __name__ == '__main__':
    main()
