class BinaryTree:

    def __init__(self, v):
        self.left = None
        self.right = None
        self.parent = None
        self.value = v
        self.replicas = 1
        self._sum = 0

    def __repr__(self):
        return str(self)

    def __str__(self):
        return "[{} {} {}] ({}) ({})".format(self.value, self._sum, self.sum, self.left, self.right)

    @property
    def sum(self):
        total = self._sum
        current = self
        while True:
            if current.parent is None:
                return total
            parent = current.parent
            if parent.value < self.value:
                total += (parent.value*parent.replicas) + parent._sum
            current = current.parent

    def insert(self, v):
        current = self
        s = 0
        while True:
            if current.value == v:
                current.replicas += 1
                return current._sum + s
            elif current.value < v:
                s += (current.value*current.replicas) + current._sum
                if current.right is None:
                    node = BinaryTree(v)
                    node.parent = current
                    current.right = node
                    return s
                else:
                    current = current.right
            else:
                current._sum += v
                if current.left is None:
                    node = BinaryTree(v)
                    node.parent = current
                    current.left = node
                    return s
                else:
                    current = current.left


def solve(stair):
    tree = BinaryTree(stair.pop(0))
    total = 0
    for step in stair:
        total += tree.insert(step)
    return total


def main():
    t = int(input())
    for i in range(t):
        size = int(input())
        stair = [int(n) for n in input().split(' ')[:size]]
        print(solve(stair))


if __name__ == "__main__":
    main()
