from typing import Generator


class Node:
    def __init__(self, key: int) -> None:
        self.key = key
        self.next: Node | None = None
    

class LinkedList:
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
    
    def build(self, keys: list[int]) -> None:
        for key in keys:
            self.insert_last(key)

    def insert_first(self, key: int) -> None:
        new_node = Node(key)
        if self.head == None:
            self.head = new_node
            return
        new_node.next = self.head
        self.head = new_node
            
    def insert_last(self, key: int) -> None:
        new_node = Node(key)
        skip = 0
        if self.head == None:
            self.head = new_node
            skip += 1
        
        current_node = self.head
        for _ in range(len(self) - skip):
            if current_node.next == None:
                current_node.next = Node(key)
            current_node = current_node.next

    def insert_at(self, index: int, key: int) -> None:
        raise NotImplementedError

    def get_at(self, i: int) -> None:
        raise NotImplementedError

    def set_at(self, i: int, key: int) -> None:
        raise NotImplementedError

    def get_by_key(self, key: int) -> None:
        raise NotImplementedError

    def delete_by_key(self, key: int) -> None:
        raise NotImplementedError
    
    def reverse(self) -> None:
        raise NotImplementedError