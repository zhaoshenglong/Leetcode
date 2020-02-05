class Solution:
    def simplifyPath(self, path: str) -> str:
        res = []
        i = 0
        sz = len(path)
        point = 0
        while i < sz:
            while path[i] == "/":
                i += 1
                if i >= sz:
                    return "/" + "/".join(res[:point])
            if path[i] == ".":
                i += 1
                if i < sz and path[i] == ".":
                    i += 1
                    if i < sz and path[i] == "/":
                        if point > 0:
                            point -= 1
                        continue
                    else:
                        if i >= sz:
                            if point > 0:
                                point -= 1
                            continue
                        else:
                            i -= 2
                else:
                    if i >= sz:
                        break
                    else:
                        if path[i] != "/":
                            i -= 1
                        else:
                            continue
            t = i
            while path[i] != "/":
                i += 1
                if i >= sz:
                    break
            if point == len(res):
                res.append(path[t:i])
            else:
                res[point] = path[t:i]
            point += 1
        return "/" + "/".join(res[:point])


def main():
    s = Solution()
    print(s.simplifyPath("/a/../../b/../c//.//"))


if __name__ == '__main__':
    main()
