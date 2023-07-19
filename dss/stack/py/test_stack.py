import unittest

from stack import Node, Stack

class TestStack(unittest.TestCase):

    def test(self):
        stack = Stack(10)
        for i in stack.array:
            self.assertEqual(i, None)
    
    def test_push(self):
        stack = Stack(10)
        for i in range(10):
            stack.push(i)
        for i in stack.array:
            assert isinstance(i, Node)
        self.assertRaises(Exception, stack.push, 11)


    def test_pop(self):
        stack = Stack(10)
        for i in range(10):
            stack.push(i)
        for i in range(10):
            stack.pop()
            assert stack.array[10 - i - 1] is None
        

if __name__ == "__main__":
    unittest.main()