import queue


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        q = queue.SimpleQueue()
        q.put((1, root))
        res = 1
        while not q.empty():
            res, p = q.get()
            if p.left:
                q.put((res + 1, p.left))
            if p.right:
                q.put((res + 1, p.right))
        return res

