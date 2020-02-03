class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        sz = len(s)
        if sz == 0:
            return 0
        i = sz - 1
        while i >= 0 and s[i] == " ":
            i -= 1
        while i >= 0:
            if s[i] == " ":
                return res
            else:
                res += 1
            i -= 1
        return res


def main():
    s = Solution()
    print(s.lengthOfLastWord("Hello "))


if __name__ == '__main__':
    main()
