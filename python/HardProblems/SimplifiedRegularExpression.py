from typing import List


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dfa: List[List[]] = [[0 for c in range('a','z')]]
        l: int = p.__len__()
        for i in range(l):
            if p[i] == '*':
                dfa[i - 1]