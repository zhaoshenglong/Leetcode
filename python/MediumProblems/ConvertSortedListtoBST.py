# Definition for singly-linked list.
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def sortedArrayToBST(nums: List[int]) -> TreeNode:
    n = len(nums)
    if n == 0:
        return None
    i = n >> 1
    root = TreeNode(nums[i])
    root.left = sortedArrayToBST(nums[:i])
    root.right = sortedArrayToBST(nums[i + 1:])
    return root


class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head:
            return None
        p = head
        a = []
        while p:
            a.append(p.val)
            p = p.next
        return sortedArrayToBST(a)
