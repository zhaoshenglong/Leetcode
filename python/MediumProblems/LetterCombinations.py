from typing import List, Dict


class Solution:
    combinations: Dict = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    def letter_combinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        res: List[str] = []
        comb: List[str] = ["" for i in range(len(digits))]
        self.recurse_combinations_helper(digits, 0, comb, res)
        return res

    def recurse_combinations_helper(self, digits: str, level: int, comb: List[str], target: List[str]):
        if level >= len(digits):
            target.append("".join(comb))
            return
        else:
            for s in self.combinations.get(digits[level]):
                comb[level] = s
                level += 1
                self.recurse_combinations_helper(digits, level, comb, target)
                level -= 1


def main():
    s = Solution()
    a = s.letter_combinations("323")
    print(a)


if __name__ == '__main__':
    main()