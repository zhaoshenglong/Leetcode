# Definition for a binary tree node.
from typing import List
import queue


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q = queue.SimpleQueue()
        q.put((0, root))
        m = 0
        res = [[]]
        while not q.empty():
            item = q.get()
            p = item[1]
            level = item[0]
            if level > m:
                m += 1
                res.append([p.val])
            else:
                res[m].append(p.val)
            if p.left:
                q.put((m + 1, p.left))
            if p.right:
                q.put((m + 1, p.right))
        return res
