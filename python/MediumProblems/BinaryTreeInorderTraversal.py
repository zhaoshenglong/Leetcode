# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def inorder_traverse(root: TreeNode, res: List):
    if root.left:
        inorder_traverse(root.left, res)
    res.append(root.val)
    if root.right:
        inorder_traverse(root.right, res)


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # res = []
        # if not root:
        #     return []
        # inorder_traverse(root, res)
        # return res
        # 以上是递归方法
        res = []
        if not root:
            return []
        stack = []
        p = root
        while stack or p:
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            res.append(p.val)
            p = p.right
        return res
        # 以上是非递归的方法


def main():
    s = Solution()
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    print(s.inorderTraversal(root))


if __name__ == '__main__':
    main()
