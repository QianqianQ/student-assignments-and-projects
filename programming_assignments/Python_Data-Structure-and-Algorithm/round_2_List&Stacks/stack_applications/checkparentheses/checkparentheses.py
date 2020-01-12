from stack import Stack

def checkParentheses(input_string):
    """Check if input_string has correctly formatted parentheses.
    If parentheses are correct, return True, else return False.

    Example behaviour:
    ================= ==============================
    input_string      checkParentheses(input_string)
    ================= ==============================
    ()                True
    (()({}))          True
    {aaa(vv)f[gg]df}  True
    a                 True
    (                 False
    (]                False
    aa(b]b)ee         False
    ({)}              False
    ================= ==============================
    """

    stack = Stack()
    if len(input_string) == 0:
        return True

    for c in input_string:
        if c == '(' or c == '{' or c == '[':
            stack.push(c)

        if c == ')' or c == '}' or c == ']':
            if (c == ')' and stack.top() == '(') or (c == '}' and stack.top() == '{') \
                    or (c == ']' and stack.top() == '['):
                stack.pop()
            else:
                return False

    if stack.is_empty():
        return True
    else:
        return False

    # raise NotImplementedError("checkParentheses not yet implemented")





