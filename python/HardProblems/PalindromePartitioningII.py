class Solution:
    def minCut(self, s: str) -> int:
        if not s:
            return 0
        sz = len(s)
        str_list = []
        for c in s:
            str_list.append(c)
        dp_dict = {-1: [], 0: [[0, 1]]}
        for i in range(1, sz):
            merged = False
            t = dp_dict[i - 1]
            l = len(t)
            a = str_list[t[-1][0]: i + 1]
            b = a.copy()
            b.reverse()
            if "".join(a) == "".join(b):
                a = t.copy()
                a[l - 1][1] = i + 1
                dp_dict[i] = a
                merged = True
            else:
                if l >= 2:
                    p = t[-2][0]
                    while p < t[-2][1]:
                        if str_list[p] == str_list[i]:
                            a = str_list[p: i + 1]
                            b = a.copy()
                            b.reverse()
                            c = str_list[t[-2][0]: p]
                            d = c.copy()
                            d.reverse()
                            if "".join(a) == "".join(b) and "".join(c) == "".join(d):
                                a = t[:-2]
                                if t[-2][0] == p:
                                    a.append([p, i + 1])
                                else:
                                    a.extend([[t[-2][0], p], [p, i + 1]])
                                dp_dict[i] = a
                                merged = True
                                break
                        p += 1
            if not merged:
                a = t.copy()
                a.append([i, i + 1])
                dp_dict[i] = a
        print(dp_dict[sz - 1])
        return len(dp_dict[sz - 1]) - 1


def main():
    s = Solution()
    print(s.minCut("ccaacabac"))

if __name__ == '__main__':
    main()
