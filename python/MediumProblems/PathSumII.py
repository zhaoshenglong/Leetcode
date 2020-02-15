# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        if not root:
            return res
        s = [(root.val, [root.val], root)]
        while s:
            t, l, p = s.pop()
            if p.left:
                path = l.copy()
                path.append(p.left.val)
                s.append((t + p.left.val, path, p.left))
            else:
                if not p.right:
                    if t == sum:
                        res.append(l)
                    continue
            if p.right:
                path = l.copy()
                path.append(p.right.val)
                s.append((t + p.right.val, path, p.right))
        return res
