# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        else:
            val = preorder[0]
            root = TreeNode(val)
            i = inorder.index(val)
            root.left = self.buildTree(preorder[1:i + 1], inorder[:i])
            root.right = self.buildTree(preorder[i + 1:], inorder[i + 1:])
            return root
