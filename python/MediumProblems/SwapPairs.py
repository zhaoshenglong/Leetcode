# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swap_pairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        lp = head
        rp = head.next
        lp_prev = ListNode(0)
        nh = head.next
        while True:
            lp.next = rp.next
            rp.next = lp
            lp_prev.next = rp
            lp_prev = lp
            lp = lp.next
            if not lp:
                break
            rp = lp.next
            if not rp:
                break
        return nh


def main():
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    a = s.swap_pairs(head)
    while a:
        print(a.val)
        a = a.next


if __name__ == '__main__':
    main()
