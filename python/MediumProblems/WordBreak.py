from typing import List



def recurse():
    pass


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # word_dict = {}
        # for w in wordDict:
        #     word_dict[w] = 1
        # stack = [s]
        # while stack:
        #     w = stack.pop()
        #     sz = len(w)
        #     for i in range(sz):
        #         if word_dict.get(w[:i + 1]) is not None:
        #             if i + 1 == sz:
        #                 return True
        #             stack.append(w[i + 1:])

        # for w in wordDict:
        #     if w == s:
        #         return True
        #     elif s.startswith(w):
        #         if self.wordBreak(s[len(w):], wordDict):
        #             return True
        # return False
        # 上面两个方法应该都是对的，但是运行效率太低了，无法通过leetcode的测试
        pass


def main():
    s = Solution()
    print(s.wordBreak("applepenapple", ["apple", "pen"]))


if __name__ == '__main__':
    main()
