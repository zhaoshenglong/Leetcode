from typing import List, Set


class Solution:
    def generate_parenthesis(self, n: int) -> List[str]:
        res: Set[str] = set()
        if n == 0:
            return [""]
        if n == 1:
            return ["()"]
        for item in self.generate_parenthesis(n - 1):
            res.add("".join(["(", item, ")"]))
        for i in range(1, (n >> 1) + 1):
            for j in range(n):
                for mitem in self.generate_parenthesis(i):
                    for litem in self.generate_parenthesis(j):
                        for ritem in self.generate_parenthesis(n - i - j):
                            res.add("".join([litem, mitem, ritem]))
        return list(res)


def main():
    s = Solution()
    print(s.generate_parenthesis(4))


if __name__ == '__main__':
    main()
