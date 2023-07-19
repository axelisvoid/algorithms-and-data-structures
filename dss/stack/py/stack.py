class Node:
    def __init__(self, element: int, key: int) -> None:
        self.element = element
        self.key = key


class Stack:
    def __init__(self, size: int) -> None:
        self.size = size
        self.array: list[None | Node] = [None for _ in range(size)]
        self.top: Node | None = None

    def is_empty(self) -> bool:
        if self.top == None:
            return True
        return False

    def push(self, element: int) -> None:
        if self.top and self.top.key == self.size:
            raise Exception("Stack overflow error. Invalid push operation")
        index = 0
        if not self.top:
            node = Node(element, index)
            self.array[index] = node
            self.top = node
            return
        index = self.top.key + 1
        node = Node(element, index)
        self.array[index] = node
        self.top = node
    
    def pop(self) -> Node:
        if self.is_empty():
            raise Exception("Stack underflow error. Invalid pop operation")
        assert self.top is not None

        index = self.top.key
        deleted_node = self.array[index]
        assert isinstance(deleted_node, Node)

        self.array[index] = None
        self.top = self.array[index - 1]
        return deleted_node

