from typing import List, Dict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res: Dict[str, List[str]] = {}
        for i in range(len(strs)):
            l = list(strs[i])
            l.sort()
            h = "".join(l)
            if res.get(h) is not None:
                res[h].append(strs[i])
            else:
                res[h] = [strs[i]]
        return list(res.values())

    """
    间隔为4,假定一个字母出现次数最多4次，相当于5进制
    """


def main():
    s = Solution()
    print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))


if __name__ == '__main__':
    main()
