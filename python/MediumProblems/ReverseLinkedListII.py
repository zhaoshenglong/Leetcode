# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        i = 1
        h = ListNode(0)
        h.next = head
        p = h
        while i < m:
            p = p.next
            i += 1
        m_node_prev = p
        p = p.next
        node_list = []
        while i <= n:
            node_list.append(p.val)
            p = p.next
            i += 1
        n_node_succ = p
        node_list.reverse()
        p = m_node_prev
        for i in node_list:
            p.next = ListNode(i)
            p = p.next
        p.next = n_node_succ
        return h.next


def main():
    s = Solution()
    p = ListNode(1)
    p.next = ListNode(2)
    p.next.next = ListNode(3)
    p.next.next.next = ListNode(4)
    p.next.next.next.next = ListNode(5)
    p = s.reverseBetween(p, 1, 5)
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()
