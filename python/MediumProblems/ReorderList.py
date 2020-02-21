# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        node_list = []
        p = head
        while p:
            node_list.append(p)
            p = p.next
        sz = len(node_list)
        prev = ListNode(1)
        for i in range(sz >> 1):
            prev.next = node_list[i]
            prev = prev.next
            prev.next = node_list[sz - i - 1]
            prev = prev.next
        if sz & 1:
            prev.next = node_list[sz >> 1]
            prev = prev.next
        prev.next = None
