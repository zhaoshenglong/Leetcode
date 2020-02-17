from typing import List


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        q = [(1, beginWord)]
        used_words = {beginWord: 1}
        words_dict = {}
        # 构建单词库
        for w in wordList:
            words_dict[w] = 1
        res = len(wordList) + 2
        idx = 0
        sz = 1
        while idx < sz:
            cnt, w = q[idx]
            idx += 1
            for i in range(len(w)):
                for j in range(97, 123):
                    new_word = "".join([w[:i], chr(j), w[i+1:]])
                    if words_dict.get(new_word) is not None:
                        if endWord == new_word and cnt < res - 1:
                            res = cnt + 1
                        elif used_words.get(new_word) is None:
                            used_words[new_word] = 1
                            q.append((cnt + 1, new_word))
                            sz += 1
        return res if res < len(wordList) + 2 else 0


def main():
    s = Solution()
    print(s.ladderLength("hog", "cog", ["cog"]))


if __name__ == '__main__':
    main()
