
import unittest
import random
from bst import BST


class TestBSTRemove(unittest.TestCase):
    def setUp(self):
        self.tree = BST()

    def _assertBSTProperty(self):
        """Assert that self.tree is a binary search tree."""
        previous_key = None
        for key in self.tree:
            if previous_key:
                self.assertLessEqual(
                    previous_key,
                    key,
                    "An inorder traversal of the tree should iterate the keys of the tree in sorted ascending order.\n\n" +
                    "(Assuming BST.__iter__ yields the keys of the tree in inorder.)"
                )
            previous_key = key

    def test1_has_all_attributes(self):
        """The BST has all required methods. (0p)"""
        method_names = (
            "find",
            "insert",
            "remove",
            "__iter__"
        )
        for attr in method_names:
            self.assertTrue(
                hasattr(BST, attr),
                "BST should have the method {0} but hasattr(BST, \"{0}\") returned False."
                .format(attr)
            )

    def test2_remove_from_empty_tree(self):
        """Removing a node from an empty tree returns None. (1p)"""
        removed = self.tree.remove(0)
        self.assertIsNone(
            removed,
            "Attempting to remove the key 0 from a tree with no nodes should return None, not {}"
            .format(removed)
        )

    def test3_remove_nonexisting_node(self):
        """Removing a node which does not exist returns None. (1p)"""
        removed = self.tree.remove(0)
        self.assertIsNone(
            removed,
            "Attempting to remove the key 0 from a tree which does not contain a node with the key 0 should return None, not {}"
            .format(removed)
        )

    def test4_remove_existing_one(self):
        """For a tree with one node, calling remove with the key of that node removes it from the tree and returns the node. (1p)"""
        inserted = self.tree.insert(1)
        removed = self.tree.remove(1)
        self.assertIs(
            removed,
            inserted,
            "After calling insert(1), calling remove(1) should return the node with the key 1 but it returned {}"
            .format(removed)
        )
        self.assertIsNone(
            self.tree.root,
            "After removing one node from a tree containing one node, the root of the tree should be None, not {}."
            .format(self.tree.root)
        )

    def test5_remove_decreases_count(self):
        """Removing an existing node decreases the node counter. (1p)"""
        self.tree.insert(1)
        self.tree.insert(2)
        self.assertEqual(
            self.tree.nodes,
            2,
            "After inserting two nodes into an initially empty tree, the node counter was {} instead of 2."
            .format(self.tree.nodes)
        )
        self.tree.remove(1)
        self.assertEqual(
            self.tree.nodes,
            1,
            "After inserting two nodes into an initially empty tree and then removing one, the node counter was {} instead of 1."
            .format(self.tree.nodes)
        )

    def test6_remove_existing_is_detached(self):
        """Removing an existing node returns the node with its references removed (left and right are None). (1p)"""
        self.tree.insert(1)
        removed = self.tree.remove(1)
        self.assertIsNone(
            removed.left,
            "After removing a node with the key 1, the left child of the removed node should be None, not {}."
            .format(removed.left)
        )
        self.assertIsNone(
            removed.right,
            "After removing a node with the key 1, the right child of the removed node should be None, not {}."
            .format(removed.right)
        )

    def test7_remove_root_of_tree_with_three_nodes(self):
        """Removing the root of a tree containing three nodes returns the root and replaces it in the tree. (1p)"""
        root = self.tree.insert(2)
        self.tree.insert(1)
        self.tree.insert(3)
        removed = self.tree.remove(2)
        self.assertIs(
            removed,
            root,
            "Calling remove for a node which exists should return the node, not {}."
            .format(removed)
        )
        new_root = self.tree.root
        if new_root.left:
            self.assertGreater(
                new_root.key,
                new_root.left.key,
                "After removing the root {0}, the new root {1} should have a key greater than its left child {2}."
                .format(root, new_root, new_root.left)
            )
        if new_root.right:
            self.assertLess(
                new_root.key,
                new_root.right.key,
                "After removing the root {0}, the new root {1} should have a key less than its right child {2}."
                .format(root, new_root, new_root.right)
            )

    def test8_remove_random(self):
        """After inserting a random amount of random integer keys and then removing a random amount of random integer keys, the tree should retain the binary search tree property. (2p)"""
        keys = random.sample(range(100), random.randint(5, 50))
        inserted = set(self.tree.insert(key) for key in keys)
        remove_count = random.randint(0, len(inserted))
        for _, node in zip(range(remove_count), inserted):
            removed = self.tree.remove(node.key)
            self.assertIs(
                removed,
                node,
                "After calling remove with the key {0}, the returned node should have been {1} but it was {2}."
                .format(node.key, node, removed)
            )
            self._assertBSTProperty()


if __name__ == '__main__':
    unittest.main(verbosity=2)




