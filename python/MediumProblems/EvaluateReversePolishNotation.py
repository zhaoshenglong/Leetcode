from typing import List

PLUS = "+"
MINUS = "-"
MULTIPLY = "*"
DIVISION = "/"


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for t in tokens:
            if t == PLUS:
                t2 = stack.pop()
                t1 = stack.pop()
                stack.append(t1 + t2)
            elif t == MINUS:
                t2 = stack.pop()
                t1 = stack.pop()
                stack.append(t1 - t2)
            elif t == MULTIPLY:
                t2 = stack.pop()
                t1 = stack.pop()
                stack.append(t1 * t2)
            elif t == DIVISION:
                t2 = stack.pop()
                t1 = stack.pop()
                stack.append(int(t1 / t2))
            else:
                stack.append(int(t))
        return stack[0]
