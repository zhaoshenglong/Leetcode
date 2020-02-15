# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        left = root.left
        right = root.right
        self.flatten(left)
        self.flatten(right)
        root.left = None
        root.right = left
        p = root
        while p.right:
            p = p.right
        p.right = right
