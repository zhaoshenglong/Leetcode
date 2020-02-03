# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        sz = 1
        p = head.next
        tail = head
        while p:
            sz += 1
            tail = p
            p = p.next

        if k % sz == 0:
            return head
        cnt = 1
        p = head
        while cnt != sz - k % sz:
            p = p.next
            cnt += 1
        t = p.next
        p.next = None
        tail.next = head
        return t


def main():
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    p = s.rotateRight(head, 6)
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()
