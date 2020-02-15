# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        s = [(1, root)]
        min_depth = 1 << 31
        while s:
            d, p = s.pop()
            if d >= min_depth:
                continue
            if p.left:
                s.append((d + 1, p.left))
            else:
                if not p.right and d < min_depth:
                    min_depth = d
            if p.right:
                s.append((d + 1, p.right))
        return min_depth
