import os
import sys
import time
from typing import List, Dict


class Solution:
    def longest_palindrome(self, s: str) -> str:
        # begin = time.process_time_ns()
        str_len: int = len(s)
        if str_len <= 1:
            return s
        valid = True
        for i in range((str_len + 1) >> 1):
            if s[i] != s[str_len - i - 1]:
                valid = False
                break
        if valid:
            return s

        # Length for every possible substr
        m: List = [0 for i in range(str_len)]
        n: List = list.copy(m)

        start: int = 0
        end: int = 0
        for j in range(str_len):
            if s[j] == s[str_len - 1]:
                m[j] = 1
            if s[str_len - 1 - j] == s[0]:
                n[j] = 1

        for i in range(1, str_len):
            left_top_diag_len: int = m[0]
            m[0] = n[i]
            for j in range(1, str_len):
                if s[str_len - i - 1] == s[j]:
                    tmp = m[j]
                    m[j] = left_top_diag_len + 1
                    left_top_diag_len = tmp

                    if m[j] > end - start:
                        valid = True
                        tmp = s[j + 1 - m[j]: j + 1]
                        for k in range((m[j] + 1) >> 1):
                            if tmp[m[j] - 1 - k] != tmp[k]:
                                valid = False
                                break
                        if valid:
                            start = j + 1 - m[j]
                            end = j + 1
                else:
                    tmp = m[j]
                    m[j] = 0
                    left_top_diag_len = tmp

        # finish = time.process_time_ns()
        # print((finish - begin) / 1000000)
        return s[start:end] if end - start > 0 else s[0]

    def is_palindrome(self, s: str) -> bool:
        l: int = s.__len__()
        for i in range(int((l + 1) / 2)):
            if s[i] != s[l - i - 1]:
                return False
        return True


def main():
    instr: str = "babd"
    s: Solution = Solution()
    print(s.longest_palindrome(instr))


if __name__ == "__main__":
    main()
