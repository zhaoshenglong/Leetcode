class Solution:
    def reverseWords(self, s: str) -> str:
        i = j = 0
        str_list = []
        sz = len(s)
        while i < sz:
            while s[i].isspace():
                if i != j:
                    str_list.append(s[j: i])
                    j = i
                i += 1
                j += 1
                if i >= sz:
                    str_list.reverse()
                    return " ".join(str_list)
            i += 1
        if i != j:
            str_list.append(s[j:i])
        str_list.reverse()
        return " ".join(str_list)


def main():
    s = Solution()
    print(s.reverseWords("  hello world!  "))


if __name__ == '__main__':
    main()
