from typing import Dict


class Solution:
    terms: Dict = {1: "1"}

    def countAndSay(self, n: int) -> str:
        if self.terms.get(n) is not None:
            return self.terms.get(n)
        else:
            s = self.countAndSay(n - 1)
            t = s[0]
            cnt = 0
            l = []
            for c in s:
                if c != t:
                    l.append(str(cnt))
                    l.append(t)
                    t = c
                    cnt = 1
                else:
                    cnt += 1
            l.append(str(cnt))
            l.append(t)
            self.terms[n] = "".join(l)
            return self.terms[n]


def main():
    s = Solution()
    print(s.countAndSay(5))


if __name__ == '__main__':
    main()
