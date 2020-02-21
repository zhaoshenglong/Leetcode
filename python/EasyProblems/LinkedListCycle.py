# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 这种方法改了原来的节点
        next_node = ListNode(-1)
        p = head
        while p:
            t = p
            p = p.next
            t.next = next_node
            if p == next_node:
                return True
        return False
