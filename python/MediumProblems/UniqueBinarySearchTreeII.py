# Definition for a binary tree node.
from typing import List
import copy


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def traverse_add(p, i):
    if not p:
        return
    p.val += i
    traverse_add(p.left, i)
    traverse_add(p.right, i)


class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        tree_map = {0: [], 1: [TreeNode(1)]}
        if n == 0 or n == 1:
            return tree_map[n]
        for i in range(2, n + 1):
            trees = []
            for t in tree_map[i - 1]:
                a = copy.deepcopy(t)
                tree_node = TreeNode(i)
                tree_node.left = a
                trees.append(tree_node)
                tree_node = TreeNode(i)
                a = copy.deepcopy(a)
                p = a
                while p.right:
                    p = p.right
                p.right = tree_node
                trees.append(a)
            for j in range(1, i):
                for t in tree_map[j]:
                    for k in tree_map[i - j - 1]:
                        up = copy.deepcopy(t)
                        p = up
                        while p.right:
                            p = p.right
                        tree_node = TreeNode(i)
                        p.right = tree_node
                        low = copy.deepcopy(k)
                        traverse_add(low, j)
                        tree_node.left = low
                        trees.append(up)
            tree_map[i] = trees
        return tree_map[n]


def inorder_traverse(root: TreeNode, res: List):
    if root.left:
        inorder_traverse(root.left, res)
    res.append(root.val)
    if root.right:
        inorder_traverse(root.right, res)


def main():
    s = Solution()
    r = s.generateTrees(4)
    for i in r:
        res = []
        inorder_traverse(i, res)
        print(res)


if __name__ == '__main__':
    main()
