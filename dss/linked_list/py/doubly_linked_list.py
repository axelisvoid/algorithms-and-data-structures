from typing import Generator

class Node:
    def __init__(self, key: int) -> None:
        self.key = key
        self.next: Node | None = None
        self.prev: Node | None  = None

class DoublyLinkedList:
    def __init__(self) -> None:
        self.head: Node | None = None
    
    def __iter__(self) -> Generator[Node, None, None]:
        node = self.head
        while node:
            yield node
            node = node.next

    def __str__(self) -> str:
        return "->".join([f"{node.key}" for node in self])

    def __len__(self) -> int:
        counter = 0
        for _ in self:
            counter += 1
        return counter

    def build(self, keys: list[Node]) -> None:
        for key in keys:
            self.insert_last(key)
    
    def insert_first(self, key: int) -> None:
        new_node = Node(key)
        if self.head is None:
            self.head = new_node
            return
        new_node.next = self.head
        self.head = new_node
    
    def insert_last(self, key: int) -> None:
        new_node = Node(key)
        skip = 0
        if self.head is None:
            self.head = new_node
            skip += 1
        
        current_node = self.head
        for _ in range(len(self) - skip):
            if current_node.next is None:
                current_node.next = new_node
            current_node = current_node.next

    def get_by_key(self, key: int) -> Node | None:
        for node in self:
            if node.key == key:
                return node
        return None
