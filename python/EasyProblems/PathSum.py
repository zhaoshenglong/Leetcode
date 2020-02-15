# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        s = [(root.val, root)]
        while s:
            t, p = s.pop()
            if p.left:
                s.append((t + p.left.val, p.left))
            else:
                if not p.right:
                    if t == sum:
                        return True
                    continue
            if p.right:
                s.append((t + p.right.val, p.right))
        return False
