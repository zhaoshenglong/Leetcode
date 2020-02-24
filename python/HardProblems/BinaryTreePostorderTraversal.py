# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack = []
        root_val = []
        p = root
        res = []
        while stack or p:
            if root_val and root_val[-1][0].right == p:
                t, v = root_val.pop()
                res.append(v)
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            root_val.append((p, p.val))
            p = p.right
        return res


def main():
    s = Solution()
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    print(s.postorderTraversal(root))


if __name__ == '__main__':
    main()
