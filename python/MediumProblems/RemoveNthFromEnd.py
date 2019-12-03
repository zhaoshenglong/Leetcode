# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def remove_nth_from_end(self, head: ListNode, n: int) -> ListNode:
        prev: ListNode = head
        cur: ListNode = head
        step: int = 0

        while cur.next is not None:
            cur = cur.next
            if step != n:
                step += 1
            else:
                prev = prev.next

        if prev != head or step == n:
            prev.next = prev.next.next
            return head
        elif step == n - 1:
            """remove head"""
            return head.next
        else:
            """list length too small"""
            assert 0


def main():
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    # head.next.next = ListNode(3)
    # head.next.next.next = ListNode(4)
    s.remove_nth_from_end(head, 1)

    p = head
    while p.next is not None:
        print("%d -> " % p.val, sep="", end="")
        p = p.next
    print("%d" % p.val)


if __name__ == '__main__':
    main()
