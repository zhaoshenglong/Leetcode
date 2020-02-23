class CacheNode:
    def __init__(self, key: int, val: int, prev=None, n=None):
        self.val = val
        self.key = key
        self.prev = prev
        self.next = n


class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
        self.head = CacheNode(1, 1)
        self.tail = CacheNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def get(self, key: int) -> int:
        if self.cache.get(key) is not None:
            val, node = self.cache[key]
            node.prev.next = node.next
            node.next.prev = node.prev

            node.prev = self.head
            node.next = self.head.next
            self.head.next.prev = node
            self.head.next = node
            return val
        else:
            return -1

    def put(self, key: int, val: int) -> None:
        if self.cache.get(key) is not None:
            _, node = self.cache[key]
            self.cache[key] = (val, node)
            node.prev.next = node.next
            node.next.prev = node.prev
            node.next = self.head.next
            node.prev = self.head
            self.head.next.prev = node
            self.head.next = node
        else:
            if self.size < self.capacity:
                t = CacheNode(key, val, self.head, self.head.next)
                self.cache[key] = (val, t)
                self.head.next.prev = t
                self.head.next = t
                self.size += 1
            else:
                last_node = self.tail.prev
                # print(last_node.key, last_node.val)
                last_node.prev.next = self.tail
                self.tail.prev = last_node.prev
                self.cache[last_node.key] = None
                last_node.key = key
                last_node.val = val
                self.cache[key] = (val, last_node)

                last_node.prev = self.head
                last_node.next = self.head.next
                self.head.next.prev = last_node
                self.head.next = last_node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

def main():
    s = LRUCache(2)
    s.put(2, 1)
    s.put(1, 1)
    s.put(2, 3)
    s.put(4, 1)
    print(s.get(1))
    print(s.get(2))
    # s.put(1, 5)
    # s.put(4, 4)
    # print(s.get(1))
    # print(s.get(2))
    # print(s.get(3))


if __name__ == '__main__':
    main()
