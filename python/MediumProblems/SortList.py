# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# def partition(start, end) -> ListNode:
#     val = start.val
#     p = start.next
#     q = q_prev = p_prev = start
#     while p != end:
#         if p.val < val:
#             q_prev = q
#             q = q.next
#             if p != q:
#                 # 交换 p,q
#                 n = p.next
#
#                 q_prev.next = p
#                 q_prev.next.next = q.next
#                 p_prev.next = q
#                 p_prev.next.next = n
#
#                 p = p_prev.next
#                 q = q_prev.next
#
#         p_prev = p
#         p = p.next
#     # 交换q 和 start
#     t = start.next
#     q_prev.next = start
#     start.next = q.next
#     q.next = t
#     return q_prev
#
# 以上的方法不改变node的值，但是较为繁琐,正确性没有完全检测(应该是对的)
def partition(start, end) -> ListNode:
    val = start.val
    p = start.next
    q = start
    while p != end:
        if p.val < val:
            q = q.next
            if p != q:
                # 交换 p,q
                t = q.val
                q.val = p.val
                p.val = t
        p = p.next
    # 交换q 和 start
    t = start.val
    start.val = q.val
    q.val = t
    return q


def sort(start, end):
    if start == end or not start.next:
        return
    elif start.next == end or not start.next.next:
        t = start.val
        if start.next.val < t:
            start.val = start.next.val
            start.next.val = t
        return
    else:
        t = start.val
        s = start.next.val
        m = start.next.next.val
        if t < s < m or m < s < t:
            start.val = s
            start.next.val = t
        elif t < m < s or s < m < t:
            start.val = m
            start.next.next.val = t
    node = partition(start, end)
    sort(start, node)
    sort(node.next, end)


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        res = ListNode(1)
        res.next = head
        sort(head, None)
        return res.next

# 以上使用的是快速排序，但是有一个测试用例会超时，这个我暂时不知道怎么优化，现在改成用堆排序试试看
def sift_up():
    pass

def sort():
    pass


def main():
    s = Solution()
    l = ListNode(1)
    l.next = ListNode(-1)
    l.next.next = ListNode(2)
    l.next.next.next = ListNode(3)
    l.next.next.next.next = ListNode(-2)
    s.sortList(l)
    p = l
    while p:
        print(p.val)
        p = p.next


if __name__ == '__main__':
    main()
