from typing import List


def recurse_restore(s, lo, sz, k, prev: List, res: List):
    if k == 1:
        if lo >= sz or sz - lo > 3 \
                or int(s[lo: sz]) > 255 \
                or (sz - lo > 1 and s[lo] == "0"):
            return
        prev.append(s[lo: sz])
        res.append(".".join(prev))
    else:
        for i in range(1, 4):
            if lo + i > sz:
                return
            elif int(s[lo: lo + i]) > 255:
                return
            elif s[lo] == "0" and i != 1:
                return
            else:
                t = prev.copy()
                t.append(s[lo: lo + i])
                recurse_restore(s, lo + i, sz, k - 1, t, res)


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        sz = len(s)
        recurse_restore(s, 0, sz, 4, [], res)
        return res


def main():
    s = Solution()
    print(s.restoreIpAddresses("2550"))


if __name__ == '__main__':
    main()
