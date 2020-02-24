class Solution:
    def remove_duplicate_letters(self, s: str) -> str:

        letter_table = {}
        res = []
        cnt: int = 0
        for i in range(len(s)):
            if letter_table.get(s[i]) is None:
                res.append(s[i])
                letter_table[s[i]] = cnt
                cnt += 1
            else:
                if letter_table[s[i]] + 1 < len(s) and s[i] > s[letter_table[s[i]] + 1]:
                    res.remove(s[i])
                    res.append(s[i])
                    letter_table[s[i]] = cnt - 1
        return "".join(res)


def main():
    s = Solution()
    print(s.remove_duplicate_letters("bcabc"))


if __name__ == '__main__':
    main()
