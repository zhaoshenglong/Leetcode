# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        res = ListNode("")
        res.next = head
        p = res.next
        prev = res
        while p:
            if p.val == prev.val:
                while p.val == prev.val:
                    p = p.next
                    if not p:
                        prev.next = None
                        return res.next
                prev.next = p
                prev = p
                p = p.next
            else:
                prev = p
                p = p.next
        return res.next


def main():
    s = Solution()
    q = ListNode(1)
    p = ListNode(1)
    q.next = p
    p.next = ListNode(2)
    p.next.next = ListNode(3)
    p.next.next.next = ListNode(3)
    p.next.next.next.next = ListNode(4)
    p = s.deleteDuplicates(q)
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()


