
class ListNode:
    """
    The LinkedList uses ListNode objects to store added values.
    This class will not be tested by the grader.

    Attributes:
      obj: Any object that need to be stored.
      follower: A ListNode object that follows this (self) ListNode object
        in the linked list.
      predecessor: A ListNode object that precedes this (self) ListNode object
        in the linked list.
    """
    def __init__(self, obj):
        """Initialize a list node object with the value obj."""
        self.obj = obj
        self.follower = None
        self.predecessor = None

    def add_after(self, node):
        """Adds node 'node' as the follower of this node."""
        tmp = self.follower
        self.follower = node
        node.predecessor = self
        node.follower = tmp
        if tmp:
            tmp.predecessor = node

    def remove_after(self):
        """Removes the follower of this node."""
        if self.follower:
            self.follower = self.follower.follower
            if self.follower:
                self.follower.predecessor = self


class LinkedList:
    """
    An implementation of a doubly linked list that uses ListNode objects
    to represent nodes in the list. List indexes start from zero.

    The list contains one head and one tail guardian node with the values None.
    These can be used to check if the head or tail has been reached.
    The guardian nodes should not be included when counting the size of the list.
    """
    def __init__(self):
        """Initialize the linked list."""
        self.ListNode = ListNode
        self.head = self.ListNode(None)
        self.tail = self.ListNode(None)
        # An empty list should only have one head node followed by a tail node
        self.head.add_after(self.tail)

    def _get_at(self, n):
        """Return the node at position 'n'."""
        if n == 0:
            return self.head

        tmp = self.head
        for i in range(n):
            if tmp:
                tmp = tmp.follower
            else:
                return None
        return tmp

        # raise NotImplementedError("_get_at not implemented")

    def add_first(self, obj):
        """Add the object 'obj' as the first node."""
        new_node = self.ListNode(obj)
        if self.head.obj is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.head.predecessor = new_node
            new_node.follower = self.head
            self.head = new_node

        # raise NotImplementedError("add_first not implemented")

    def add_last(self, obj):
        """Add the object 'obj' as the last node."""
        new_node = self.ListNode(obj)
        if self.head.obj is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.add_after(new_node)
            self.tail = new_node

        # raise NotImplementedError("add_last not implemented")

    def add_position(self, n, obj):
        """Insert the object 'obj' as the 'n'th node."""
        new_node = self.ListNode(obj)
        if n == 0:
            self.add_first(obj)
        else:
            current = self._get_at(n-1)
            current.add_after(new_node)

    # raise NotImplementedError("add_position not implemented")

    def remove_position(self, n):
        """Remove the node at the 'n'th position."""
        if n == 0:
            self.head = self.head.follower
            if self.head:
                self.head.predecessor = None

        if isinstance(self._get_at(n), ListNode):
            predecessor = self._get_at(n).predecessor
            if predecessor:
                predecessor.remove_after()

    def get_position(self, n):
        """Return the value of the node at the 'n'th position or None
        if there is no node at that position."""
        node = self._get_at(n)
        if node:
            return node.obj
        else:
            return None

    def get_size(self):
        """Return the number of objects in the list."""
        n = 0
        tmp = self.head
        while isinstance(tmp, ListNode):
            if tmp.obj is not None:
                n += 1
            tmp = tmp.follower
        return n

        # raise NotImplementedError("get_size not implemented")
