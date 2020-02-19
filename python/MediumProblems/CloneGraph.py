# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=[]):
        self.val = val
        self.neighbors = neighbors


class Solution:
    def cloneGraph(self, node: Node) -> Node:
        if not node:
            return None
        q = [node]
        i = 0
        sz = 1
        cloning_node = {}  # 已经复制了val，但是没有复制自己的邻居
        cloned_node = {}  # 已经复制了val和neighbors， 不需要再复制了
        while i < sz:
            val = q[i].val
            neighbors = q[i].neighbors
            if cloned_node.get(val) is None:
                # 是不是已经复制了val但是没有复制邻居
                if cloning_node.get(val) is not None:
                    t = cloning_node[val]
                else:
                    t = Node(val)

                for n in neighbors:
                    if cloning_node.get(n.val) is not None:
                        new_node = cloning_node[n.val]
                    elif cloned_node.get(n.val) is not None:
                        new_node = cloned_node[n.val]
                    else:
                        new_node = Node(n.val)
                        cloning_node[n.val] = new_node
                    t.neighbors.append(new_node)
                    q.append(n)  # 加到队列结尾
                    sz += 1
                q[i] = t  # 利用废弃的队列前部
                cloned_node[val] = t  # 已经复制好了
            i += 1
        return q[0]

