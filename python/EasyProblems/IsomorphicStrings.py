class Solution:
    def is_isomorphic(self, s: str, t: str) -> bool:
        isomorphic_table = {}
        used_table = {}
        for i in range(len(s)):
            if isomorphic_table.get(s[i]) is None:
                if used_table.get(t[i]) is not None:
                    return False
                isomorphic_table[s[i]] = t[i]
                used_table[t[i]] = t[i]
            else:
                if isomorphic_table.get(s[i]) != t[i]:
                    return False
        return True
