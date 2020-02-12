class Solution:
    def numTrees(self, n: int) -> int:
        tree_map = {0: 0, 1: 1, 2: 2}
        if n <= 2:
            return tree_map[n]
        for i in range(3, n + 1):
            r = tree_map[i - 1] << 1
            for j in range(1, i):
                r += tree_map[j] * tree_map[i - j - 1]
            tree_map[i] = r
        return tree_map[n]


def main():
    s = Solution()
    print(s.numTrees(3))


if __name__ == '__main__':
    main()
