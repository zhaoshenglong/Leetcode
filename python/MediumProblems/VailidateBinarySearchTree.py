# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        # 方法一，递归方法
        if not root:
            return True
        p = root.left
        if p:
            while p.right:
                p = p.right
            if p.val >= root.val:
                return False
        p = root.right
        if p:
            while p.left:
                p = p.left
            if p.val <= root.val:
                return False
        if not self.isValidBST(root.left):
            return False
        return self.isValidBST(root.right)

