from stack import Stack

def reverseObjects(sequence):
    """Returns the contents of sequence reversed in a list."""
    reversed_list = []
    stack = Stack()

    if len(sequence) == 0:
        return []

    if len(sequence) == 1:
        if isinstance(sequence, list):
            return sequence
        else:
            reversed_list.append(sequence)
            return reversed_list

    for i in sequence:
        stack.push(i)

    for j in range(len(sequence)-1):
        temp = stack.pop()
        reversed_list.append(temp)

    reversed_list.append(stack.top())
    return reversed_list



