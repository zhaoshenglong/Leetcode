# Definition for singly-linked list.
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def merge_k_lists(self, lists: List[ListNode]) -> ListNode:
        sorted_lists: List[ListNode] = []
        if len(lists) == 0:
            return None
        for i in range(len(lists)):
            p = lists[i]
            while p is not None:
                sorted_lists.append(p)
                p = p.next

        def sort_key(ele: ListNode):
            return ele.val

        sorted_lists.sort(key=sort_key)
        for i in range(len(sorted_lists) - 1):
            sorted_lists[i].next = sorted_lists[i + 1]
        if len(sorted_lists) > 0:
            sorted_lists[len(sorted_lists) - 1].next = None
            return sorted_lists[0]
        else:
            return None



def main():
    s = Solution()
    lists = [
        ListNode(1),
        ListNode(1),
        ListNode(2)
    ]
    lists[0].next = ListNode(4)
    lists[0].next.next = ListNode(5)
    lists[1].next = ListNode(3)
    lists[1].next.next = ListNode(4)
    lists[2].next = ListNode(6)
    sl = s.merge_k_lists(lists)
    p = sl
    while p:
        print(p.val, end="->")
        p = p.next


if __name__ == '__main__':
    main()
