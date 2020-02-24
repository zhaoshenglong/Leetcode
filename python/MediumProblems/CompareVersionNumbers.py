class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_list = version1.split(".")
        v2_list = version2.split(".")
        sz1 = len(v1_list)
        sz2 = len(v2_list)
        if sz1 < sz2:
            v1_list.extend(["0" for _ in range(sz2 - sz1)])
        elif sz1 > sz2:
            v2_list.extend(["0" for _ in range(sz1 - sz2)])
        for i in range(len(v1_list)):
            if int(v1_list[i]) > int(v2_list[i]):
                return 1
            elif int(v1_list[i]) < int(v2_list[i]):
                return -1
        return 0
