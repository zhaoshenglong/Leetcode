# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        merge: ListNode
        if l1.val > l2.val:
            merge = ListNode(l2.val)
            l2 = l2.next
        else:
            merge = ListNode(l1.val)
            l1 = l1.next

        p: ListNode = merge
        while l1 and l2:
            if l1.val >= l2.val:
                p.next = ListNode(l2.val)
                l2 = l2.next
            else:
                p.next = ListNode(l1.val)
                l1 = l1.next
            p = p.next
        if not l1:
            while l2:
                p.next = ListNode(l2.val)
                l2 = l2.next
                p = p.next
        if not l2:
            while l1:
                p.next = ListNode(l1.val)
                l1 = l1.next
                p = p.next
        return merge


def main():
    l1: ListNode = ListNode(-9)
    l1.next = ListNode(3)
    l2: ListNode = ListNode(5)
    l2.next = ListNode(7)

    res: ListNode = Solution().mergeTwoLists(l1, l2)

    while res:
        print(res.val, sep=",", end="")
        res = res.next


if __name__ == '__main__':
    main()
