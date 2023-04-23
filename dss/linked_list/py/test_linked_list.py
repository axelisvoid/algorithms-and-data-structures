import unittest

from linked_list import LinkedList

class TestLinkedList(unittest.TestCase):

    def test_build(self) -> None:
        linked_list = LinkedList()
        keys = [_ for _ in range(10)]
        linked_list.build(keys)
        self.assertEqual(len(linked_list), len(keys))
        for i, node in enumerate(linked_list):
            self.assertEqual(keys[i], node.key)
    
    def test_insert_last(self) -> None:
        linked_list = LinkedList()
        linked_list.insert_last(1)
        self.assertEqual(len(linked_list), 1)
        for node in linked_list:
            self.assertEqual(node.key, 1)

