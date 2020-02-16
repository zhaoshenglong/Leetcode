# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: Node) -> Node:
        if not root:
            return root
        p = root
        prev = None
        first = None
        while p:
            if prev:
                if p.left:
                    prev.next = p.left
                    prev = p.left
                if p.right:
                    prev.next = p.right
                    prev = p.right
            else:
                if p.left:
                    first = p.left
                    prev = p.left
                    if p.right:
                        prev.next = p.right
                        prev = p.right
                else:
                    if p.right:
                        first = p.right
                        prev = p.right
            p = p.next
        self.connect(first)
        return root
