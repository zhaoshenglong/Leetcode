from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        prev = [1]
        for i in range(rowIndex):
            r = [1]
            for j in range(len(prev) - 1):
                r.append(prev[j] + prev[j + 1])
            r.append(1)
            prev = r
        return prev