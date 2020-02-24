class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        minus = numerator * denominator < 0
        numerator = numerator if numerator > 0 else -numerator
        denominator = denominator if denominator > 0 else -denominator
        s = int(numerator / denominator)
        res = [str(s)]
        t = numerator - (denominator * s)
        if t > 0:
            res.append(".")
        else:
            if minus:
                return str(-int(numerator / denominator))
            else:
                return str(int(numerator / denominator))
        numerator = t * 10

        fraction_dict = {}
        sz = len(res)
        while True:
            s = int(numerator / denominator)
            t = numerator - (s * denominator)
            if t == 0:
                res.append(str(s))
                break
            if fraction_dict.get((s, t)) is not None:
                idx = fraction_dict[(s, t)]
                res.insert(idx, "(")
                res.append(")")
                break
            else:
                res.append(str(s))
                fraction_dict[(s, t)] = sz
                sz += 1
                numerator = t * 10
        if minus:
            res.insert(0, "-")
        return "".join(res)


def main():
    s = Solution()
    print(s.fractionToDecimal(-50, 2))


if __name__ == '__main__':
    main()
