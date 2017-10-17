from linkedlist import LinkedList


class Stack:
    """
    An implementation of a stack structure which utilizes the LinkedList class.

    Attributes:
        stack (LinkedList): A linked list that is used to store the objects added into the stack.
    """
    def __init__(self):
        """Initialize the stack."""
        self.stack = LinkedList()

    def push(self, obj):
        """Add the object 'obj' to the stack."""
        new_node = self.stack.ListNode(obj)
        if self.stack.head.obj is None:
            self.stack.head = new_node
            self.stack.tail = new_node
        else:
            self.stack.head.predecessor = new_node
            new_node.follower = self.stack.head
            self.stack.head = new_node

        # raise NotImplementedError('Fix me!')

    def pop(self):
        """Return and remove the newest (previously added) object from the stack."""
        if self.is_empty():
            return None
        temp = self.stack.head
        self.stack.head = self.stack.head.follower
        if self.stack.head:
            self.stack.head.predecessor = None
        return temp.obj

        # raise NotImplementedError('Fix me!')

    def top(self):
        """Return the newest (previously added) object."""
        if self.stack.head is None:
            return None
        elif self.stack.head.obj is not None:
            return self.stack.head.obj
        else:
            return None

        # raise NotImplementedError('Fix me!')

    def is_empty(self):
        """If stack has no objects, return True, else return False."""
        if self.stack.head is None:
            return True
        elif self.stack.head.obj is None:
            return True
        else:
            return False
        # raise NotImplementedError('Fix me!')

