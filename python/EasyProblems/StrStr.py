class Solution:
    def contains(self, s:str, t:str) -> int:
        if t == "":
            return 0
        j: int = 0
        i: int = 0

        tlen: int = t.__len__()
        slen: int = s.__len__()
        while i < slen - tlen + 1:
            tmp: int = 0
            while j < tlen and i < slen and s[i] == t[j]:
                i += 1
                j += 1
                if tmp == 0 and i < slen and t[0] == s[i]:
                    tmp = i
            if j == tlen and s[i - 1] == t[j - 1]:
                return i - tlen
            else:
                if j > 0 and tmp != 0:
                    i = tmp
                else:
                    i += 1
            j = 0
        return -1


def main():
    s: Solution = Solution()
    print(s.contains("mississippi", "iss"))


if __name__ == '__main__':
    main()
