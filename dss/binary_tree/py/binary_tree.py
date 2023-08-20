from __future__ import annotations
from typing import Any, Generator, Iterable, Optional


class BinarySearchTreeNode:
    """Implementation of a Binary Search Tree node"""

    def __init__(self, item: Any) -> None:
        assert item.key
        assert isinstance(item.key, int)
        self.item = item
        self.left: Optional[BinarySearchTreeNode] = None
        self.right: Optional[BinarySearchTreeNode] = None
        self.parent: Optional[BinarySearchTreeNode] = None

    def __str__(self) -> str:
        return f"{self.item}"

    def __iter__(self) -> Iterable[BinarySearchTreeNode]:
        return self.inorder_traverse()

    def inorder_traverse(self) -> Generator[BinarySearchTreeNode, None, None]:
        """Traverse the subtree in the order `left` -> `self` -> `right`."""

        if self.left:
            yield from self.left.inorder_traverse()
        yield self
        if self.right:
            yield from self.right.inorder_traverse()

    def preorder_traverse(self) -> Generator[BinarySearchTreeNode, None, None]:
        """Traverse the subtree in the order `self` -> `left` -> `right`."""

        yield self
        if self.left:
            yield from self.left.preorder_traverse()
        if self.right:
            yield from self.right.preorder_traverse()

    def postorder_traverse(self) -> Generator[BinarySearchTreeNode, None, None]:
        """Traverse the subtree in the order `left` -> `right` -> `self`."""

        if self.left:
            yield from self.left.postorder_traverse()
        if self.right:
            yield from self.right.postorder_traverse()
        yield self

    def successor(self) -> Optional[BinarySearchTreeNode]:
        """Return the next item in the subtree order."""

        if not (self.parent or self.right):
            return None
        if self.right:
            return self.right.min()

        current_node = self
        while current_node.parent and current_node.parent.right is current_node:
            current_node = current_node.parent
        return current_node.parent

    def predecessor(self) -> Optional[BinarySearchTreeNode]:
        """Return the previous node in the subtree order."""

        if not (self.parent or self.left):
            return None
        if self.left:
            return self.left.max()

        current_node = self
        while current_node.parent and current_node.parent.left is current_node:
            current_node = current_node.parent
        return current_node.parent

    def min(self) -> BinarySearchTreeNode:
        """Return the node with the key of minimum magnitude."""
        if not self.left:
            return self
        return self.left.min()

    def max(self) -> Optional[BinarySearchTreeNode]:
        """Return the node with the key of greatest magnitude."""
        if not self.right:
            return self
        return self.right.max()

    def prepend(self, other: BinarySearchTreeNode) -> None:
        """Insert `other` before the current node."""

        if not self.left:
            self.left, other.parent = other, self
            return
        predecessor = self.predecessor()
        predecessor.right, other.parent = other, predecessor

    def append(self, other: BinarySearchTreeNode) -> None:
        """Insert `other` before the current node."""

        if not self.right:
            self.right, other.parent = other, self
            return
        successor = self.successor()
        successor.left, other.parent = other, successor

    def delete(self):
        """Deletes `self` from subtree while keeping traverse order."""

        if not (self.left or self.right):
            if not self.parent:
                return self
            if self.parent.right is self:
                self.parent.right = None
            else:
                self.parent.left = None
            self.parent = None
            return self

        if self.left:
            replace_node = self.predecessor()
        else:
            replace_node = self.successor()
        replace_node.item, self.item = self.item, replace_node.item
        return self.delete()

    def find(self, key: int) -> Optional[BinarySearchTreeNode]:
        """Finds a node from this subtree with key `key`.
        
        Returns `None` if it wasn't found.
        """

        if key < self.item.key:
            return self.left.find(key)
        if key > self.item.key:
            return self.right.find(key)
        if key == self.item.key:
            return self
        return None

    def find_prev(self, key: int) -> Optional[BinarySearchTreeNode]:
        """Finds the node to the left of the item containing the `key` and
        returns it. If no item with `key` is found, returns `None`.
        """
        node = self.find(key)
        if not node:
            return None
        return node.predecessor()

    def find_next(self, key: int) -> Optional[BinarySearchTreeNode]:
        """Finds the node to the right of the item containing the `key` and
        returns it. If no item with `key` is found, returns `None`.
        """
        node = self.find(key)
        if not node:
            return None
        return node.successor()

    def fast_find_next(self, key: int) -> Optional[BinarySearchTreeNode]:
        """A faster implementation of `find_next`. Use this version."""

        if self.item.key <= key:
            if self.right:
                return self.right.alternative_find_next(key)
            return None
        if self.left:
            next_ = self.left.alternative_find_next(key)
            if next_:
                return next_
        return self

    def fast_find_prev(self, key: int) -> Optional[BinarySearchTreeNode]:
        """A faster implementation of `find_prev`. Use this version."""

        if self.item.key >= key:
            if self.left:
                return self.left.fast_find_prev(key)
            return None
        if self.right:
            prev = self.right.fast_find_prev(key)
            if prev:
                return prev
        return None

    def _insert_before(self, item: Any) -> BinarySearchTreeNode:
        pass

    def _insert_after(self, item: Any) -> BinarySearchTreeNode:
        pass

    def insert(self, item: Any) -> BinarySearchTreeNode:
        assert item.key
        assert isinstance(item.key, int)
        pass


class BinarySearchTree:
    """Implementation of a Binary Search Tree"""

    def __init__(self) -> None:
        self.root: Optional[BinarySearchTreeNode] = None
        self.size: int = 0

    def __len__(self) -> int:
        return self.size

    def __iter__(self) -> Iterable[BinarySearchTreeNode]:
        if isinstance(self.root, BinarySearchTreeNode):
            for node in self.root:  # pylint: disable=not-an-iterable
                yield node

    def build(self, items: list[Any]) -> None:
        """Build a Binary Search Tree with the `items` middle element as root.

        This method assumes that every element in the `items` list contains a
        `key` attribute whose type is `int`.
        """

        for item in items:
            assert item.key
            assert isinstance(item.key, int)
        self.root = self._build_subtree(items, 0, len(items) - 1)

    def insert(self, item: Any) -> BinarySearchTreeNode:
        pass

    def delete(self, key: int) -> BinarySearchTreeNode:
        pass

    def find(self, key: int) -> BinarySearchTreeNode:
        assert self.root
        node = self.root.find(key)
        if node:
            return node.item
        return None

    def max(self) -> BinarySearchTreeNode:
        assert self.root
        node = self.root.max()
        if node:
            return node.item
        return None

    def min(self) -> BinarySearchTreeNode:
        assert self.root
        node = self.root.min()
        if node:
            return node.item
        return None

    def find_next(self, key: int) -> Optional[BinarySearchTreeNode]:
        assert self.root
        node = self.root.fast_find_next(key)
        if node:
            return node.item
        return None

    def find_prev(self, key: int) -> Optional[BinarySearchTreeNode]:
        assert self.root
        node = self.root.fast_find_prev(key)
        if node:
            return node.item
        return None

    def _build_subtree(self, array: list[Any], start: int, end: int) -> None:
        """Builds a subtree."""

        middle = (end + start) // 2
        head = array[middle]
        if start < middle:
            head.left = self._build_subtree(array, start, middle - 1)
            head.left.parent = head
        if middle < end:
            head.right = self._build_subtree(array, middle + 1, end)
            head.right.parent = head
        return head
    