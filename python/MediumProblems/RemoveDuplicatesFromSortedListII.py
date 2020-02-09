# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        res = ListNode("")
        res.next = head
        prev = res
        cur = head
        p = head.next
        duplicate = False
        while p:
            while p.val == cur.val:
                p = p.next
                duplicate = True
                if not p:
                    prev.next = None
                    return res.next
            if duplicate:
                prev.next = p
                cur = p
                p = p.next
                duplicate = False
            else:
                prev = cur
                cur = p
                p = p.next
        return res.next


def main():
    s = Solution()
    p = ListNode(1)
    p.next = ListNode(2)
    p.next.next = ListNode(3)
    p.next.next.next = ListNode(3)
    p.next.next.next.next = ListNode(4)
    p = s.deleteDuplicates(p)
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()
