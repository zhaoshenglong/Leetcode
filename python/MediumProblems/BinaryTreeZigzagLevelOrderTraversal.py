# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


S1 = 0
S2 = 1


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
            if not root:
                return []
            res = [[]]
            s1 = [(0, root)]
            s2 = []
            m = 0
            order = S1
            while s1 or s2:
                if order == S1:
                    level, p = s1.pop()
                    if not s1:
                        order = S2
                    if m < level:
                        m += 1
                        res.append([p.val])
                    else:
                        res[m].append(p.val)
                    if p.left:
                        s2.append((m + 1, p.left))
                    if p.right:
                        s2.append((m + 1, p.right))
                else:
                    level, p = s2.pop()
                    if not s2:
                        order = S1
                    if m < level:
                        m += 1
                        res.append([p.val])
                    else:
                        res[m].append(p.val)
                    if p.right:
                        s1.append((m + 1, p.right))
                    if p.left:
                        s1.append((m + 1, p.left))
            return res
