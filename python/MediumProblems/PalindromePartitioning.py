from typing import List
import copy


class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s:
            return []
        dp_map = {-1: [[]], 0: [[s[0]]]}
        sz = len(s)
        for i in range(1, sz):
            r = copy.deepcopy(dp_map[i - 1])
            c = s[i]
            for item in r:
                item.append(c)
            k = i - 1
            while k >= 0:
                if s[k] == c:
                    # 判断是不是回文
                    is_palindrome = True
                    p, q = k + 1, i - 1
                    while p <= q:
                        if s[p] != s[q]:
                            is_palindrome = False
                        p += 1
                        q -= 1
                    if is_palindrome:
                        t = copy.deepcopy(dp_map[k - 1])
                        for item in t:
                            item.append(s[k:i + 1])
                        r.extend(t)
                k -= 1
            dp_map[i] = r
            # print(r)
        return dp_map[sz - 1]


def main():
    s = Solution()
    print(s.partition("cdd"))


if __name__ == '__main__':
    main()
