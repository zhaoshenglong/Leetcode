# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def recurse_check(p: TreeNode, q: TreeNode) -> bool:
    if not p and q or p and not q:
        return False
    if not p and not q:
        return True
    if p.val != q.val:
        return False
    if not recurse_check(p.left, q.right):
        return False
    return recurse_check(p.right, q.left)


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        p = root.left
        q = root.right
        return recurse_check(p, q)

