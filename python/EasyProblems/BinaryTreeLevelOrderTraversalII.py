# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q = [(0, root)]
        sz = 1
        idx = 0
        m = 0
        res = [[]]
        while idx < sz:
            level, p = q[idx]
            idx += 1
            if level > m:
                m += 1
                res.append([p.val])
            else:
                res[m].append(p.val)
            if p.left:
                q.append((m + 1, p.left))
                sz += 1
            if p.right:
                q.append((m + 1, p.right))
                sz += 1
        res.reverse()
        return res
