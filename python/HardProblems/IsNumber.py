from typing import List


class Solution:
    """
        Solution of automaton, use regex to represent numbers
        and parse by automaton.

        regex:
            int: [+-]?[0-9]+
            number: int.int
                    | int e int
                    | int.int e int
        automaton:
             + - 0 1 2 3 4 5 6 7 8 9 . e
           1 2 2 4 4 4 4 4 4 4 4 4 4 3
           2     4 4 4 4 4 4 4 4 4 4 3
           3     9 9 9 9 9 9 9 9 9 9 9
           4     4 4 4 4 4 4 4 4 4 4 5 7
           5     6 6 6 6 6 6 6 6 6 6   7
         * 6     6 6 6 6 6 6 6 6 6 6   7
           7 8 8 9 9 9 9 9 9 9 9 9 9
           8     9 9 9 9 9 9 9 9 9 9
         * 9     9 9 9 9 9 9 9 9 9 9

         * means accepting state
    """
    table: List[dict]

    def __init__(self):
        Solution.table = [
            {},
            {'+': 2, '-': 2, '0': 4, '.': 3},
            {'.': 3, '0': 4},
            {'0': 6},
            {'.': 5, 'e': 7, '0': 4},
            {'0': 6, 'e': 7},
            {'e': 7, '0': 6},
            {'+': 8, '-': 8, '0': 9},
            {'0': 9},
            {'0': 9},
        ]

    def isNumber(self, s: str) -> bool:
        state: int = 1
        s = s.strip()
        for c in s:
            try:
                if ord('9') >= ord(c) >= ord('0'):
                    state = Solution.table[state]['0']
                else:
                    state = Solution.table[state][c]
            except KeyError:
                return False

        if state == 4 or state == 5 or state == 6 or state == 9:
            return True
        else:
            return False


def main():
    s: Solution = Solution()
    print(s.isNumber(".0e"))


if __name__ == '__main__':
    main()
