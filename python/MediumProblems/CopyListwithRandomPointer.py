# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Node) -> Node:
        if not head:
            return None
        cloned_nodes = {}
        cloning_nodes = {head: Node(head.val)}
        p = head
        while p:
            if cloned_nodes.get(p) is None:
                if cloning_nodes.get(p) is not None:
                    new_node = cloning_nodes[p]
                else:
                    new_node = Node(p.val)

                # 添加p.next
                if cloning_nodes.get(p.next) is not None:
                    new_node.next = cloning_nodes[p.next]
                else:
                    if p.next:
                        new_node.next = Node(p.next.val)
                        cloning_nodes[p.next] = new_node.next
                    else:
                        new_node.next = None

                # 添加p.random
                if cloned_nodes.get(p.random) is not None:
                    new_node.random = cloned_nodes[p.random]
                elif cloning_nodes.get(p.random) is not None:
                    new_node.random = cloning_nodes[p.random]
                else:
                    if p.random:
                        new_node.random = Node(p.random.val)
                        cloning_nodes[p.random] = new_node.random
                    else:
                        new_node.random = None
                cloned_nodes[p] = new_node
            p = p.next
