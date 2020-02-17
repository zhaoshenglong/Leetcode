# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        s = [(root.val, root)]
        res = 0
        while s:
            sum_val, p = s.pop()
            if not p.left and not p.right:
                res += sum_val
            else:
                if p.left:
                    s.append((sum_val * 10 + p.left.val, p.left))
                if p.right:
                    s.append((sum_val * 10 + p.right.val, p.right))
        return res
