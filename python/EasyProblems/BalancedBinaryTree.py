# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def depth(root: TreeNode) -> int:
    if not root:
        return 0
    left, right = depth(root.left), depth(root.right)
    return left + 1 if left > right else right + 1


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        left, right = depth(root.left), depth(root.right)
        if abs(left - right) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
