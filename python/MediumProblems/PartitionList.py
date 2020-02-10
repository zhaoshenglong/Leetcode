# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        great_equal = ListNode(0)
        g = great_equal
        less = ListNode(0)
        l = less
        p = head
        while p:
            if p.val < x:
                l.next = ListNode(p.val)
                l = l.next
            else:
                g.next = ListNode(p.val)
                g = g.next
            p = p.next
        l.next = great_equal.next
        return less.next


def main():
    s = Solution()
    p = ListNode(1)
    p.next = ListNode(4)
    p.next.next = ListNode(3)
    p.next.next.next = ListNode(2)
    p.next.next.next.next = ListNode(5)
    p.next.next.next.next.next = ListNode(2)
    p = s.partition(p, 3)
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()
