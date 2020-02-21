# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        p = head
        while p:
            print(id(p))
            p = p.next


def main():
    s = Solution()
    p = ListNode(1)
    p.next = ListNode(2)

    s.detectCycle(p)


if __name__ == '__main__':
    main()
