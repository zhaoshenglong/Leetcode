from typing import List


class Solution:
    def longest_palindrome(self, s: str) -> str:
        l: int = s.__len__()
        m: List[List[str]] = [["" for i in range(l)] for i in range(l)]

        substr_lst: List[str] = []

        for i in range(l):
            if s[i] == s[l - 1]:
                m[0][i] = s[i]
                substr_lst.insert(0, s[i])
            if s[0] == s[l - i - 1]:
                m[i][0] = s[0]
                substr_lst.insert(0, s[0])

        for i in range(1, l):
            for j in range(1, l):
                if s[l - i - 1] == s[j]:
                    m[i][j] = m[i - 1][j - 1] + s[j]
                    substr_lst.insert(0, m[i][j])
        res: str = ""
        for s in substr_lst:
            if self.is_palindrome(s):
                if s.__len__() > res.__len__():
                    res = s

        return res

    def is_palindrome(self, s:str) -> bool:
        l: int = s.__len__()
        for i in range(int((l + 1) / 2)):
            if s[i] != s[l - i - 1]:
                return False
        return True


def main():
    instr: str = "babad"
    s: Solution = Solution()
    print(s.longest_palindrome(instr))


if __name__ == "__main__":
    main()
