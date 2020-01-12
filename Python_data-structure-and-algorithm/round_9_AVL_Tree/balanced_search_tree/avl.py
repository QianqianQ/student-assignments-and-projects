import bst

'''
Familiarize yourself with the implementation of an AVL-tree found in the exercise package.
    The class is implemented as a subclass of the binary search tree ``bst.BST``
    from the previous exercise round.
    The AVL-tree already has the functionality to calculate the balance factors
    of its nodes and choosing correctly the required rotations in order to
    keep the tree balanced.
    The method responsible of a single right rotation has also been
    implemented.
    However, the single left rotation and both double rotations are still
    missing.
    Your task is to implement these 3 methods.

    During grading, your solution will be given access to the model solution of the ``bst`` module.
    Thus you should not rely on possible extra methods etc. you may have
    implemented in the binary search tree ``bst.BST`` during the previous round.
    '''

class InvalidAVLBalance(Exception):
    def __init__(self, node, balance_factor):
        super().__init__(
            "Invalid AVL tree, the balance_factor of node {0!r} was larger than expected: {1:d}"
            .format(node, balance_factor)
        )


class AVL(bst.BST):
    """
    Simple self-balancing AVL tree.
    """
    def right_rotation(self, node):
        """Perform an in-place right rotation at node and return the node that replaces node after the rotation."""
        if node is None or node.left is None:
            raise RuntimeError("Cannot perform right rotation at node {0!r} if the node is None or has no left subtree".format(node))
        # Check out the Wikipedia page on tree rotations for some nice illustrations.
        P, Q = node.left, node
        # Move references
        P.right, Q.left = Q, P.right
        # Return the new node so the caller of this method can reassing possible
        # parent references.
        return P


    # Implement the methods below

    def left_rotation(self, node):
        """Perform an in-place left rotation at node and return the node that replaces node after the rotation."""
        if node is None or node.right is None:
            raise RuntimeError("Cannot perform left rotation at node {0!r} if the node is None or has no right subtree".format(node))
        P,Q = node.right,node
        P.left, Q.right = Q, P.left
        return P
        
        #raise NotImplementedError("This AVL tree does not yet know how to do left rotations.")

    def double_left_right_rotation(self, node):
        """Perform an in-place left-right double rotation at node and return the node that replaces node after the rotation."""
        Q = self.left_rotation(node.left)
        node.left = Q
        P = self. right_rotation(node)
        return P
        # raise NotImplementedError("This AVL tree does not yet know how to do double left-right rotations.")

    def double_right_left_rotation(self, node):
        """Perform an in-place right-left double rotation at node and return the node that replaces node after the rotation."""
        Q = self.right_rotation(node.right)
        node.right = Q
        P = self.left_rotation(node)
        return P
        #raise NotImplementedError("This AVL tree does not yet know how to do double right-left rotations.")

    # Implement the methods above


    def _inserthelp(self, node, new_key, value):
        """Insert as in BST but also rebalance the node if it is unbalanced."""
        node = super()._inserthelp(node, new_key, value)
        return self.rebalance_node(node)

    def rebalance_node(self, node):
        """Rebalance this node if it is unbalanced. The tree is modified in-place."""
        # 'node' is balanced if balance_factor is in the set {-1, 0, 1}
        balance_factor = self._balance_factor(node)

        if balance_factor < -1:
            # 'node' is unbalanced on the left side
            # Get balance factor of the left child
            node_left_balance_factor = self._balance_factor(node.left)

            if node_left_balance_factor < 0:
                # Case 1, the unbalancing node is node.left.left
                node = self.right_rotation(node)
            elif node_left_balance_factor > 0:
                # Case 2, the unbalancing node is node.left.right
                node = self.double_left_right_rotation(node)
            else:
                raise InvalidAVLBalance(node, 0)

        elif balance_factor > 1:
            # 'node' is unbalanced on the right side
            node_right_balance_factor = self._balance_factor(node.right)

            if node_right_balance_factor < 0:
                # Case 3, the unbalancing node is node.right.left
                node = self.double_right_left_rotation(node)
            elif node_right_balance_factor > 0:
                # Case 4, the unbalancing node is node.right.right
                node = self.left_rotation(node)
            else:
                raise InvalidAVLBalance(node, 0)

        elif abs(balance_factor) > 2:
            # The tree has not been rebalanced after some operation
            raise InvalidAVLBalance(node, balance_factor)

        return node

    def _balance_factor(self, node):
        """Returns the AVL balance factor of node."""
        right_height = node.right.height() if node.right else 0
        left_height = node.left.height() if node.left else 0
        return right_height - left_height

