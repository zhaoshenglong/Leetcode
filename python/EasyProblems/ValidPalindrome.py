class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        """
        A -> 65
        Z -> 90
        a -> 97
        z -> 122
        0 -> 48
        9 -> 57
        """
        while i < j:
            t = ord(s[i])
            while not (65 <= t <= 90 or 97 <= t <= 122 or 48 <= t <= 57):
                i += 1
                if i > j:
                    return True
                t = ord(s[i])
            t = ord(s[j])
            while not (65 <= t <= 90 or 97 <= t <= 122 or 48 <= t <= 57):
                j -= 1
                if i > j:
                    return True
                t = ord(s[j])
            if s[i].lower() != s[j].lower():
                return False
            else:
                i += 1
                j -= 1
        return True


def main():
    s = Solution()
    print(s.isPalindrome("A man, a plan, a canal: Panama"))


if __name__ == '__main__':
    main()
