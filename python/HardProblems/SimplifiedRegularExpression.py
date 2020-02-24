from typing import List, Dict, Tuple


class Solution:

    def is_match(self, s: str, p: str) -> bool:
        if p == "":
            return s == ""
        i = 0
        j = 0

