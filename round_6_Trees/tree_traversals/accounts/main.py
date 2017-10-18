import accounts


def main():
    nodes = [accounts.AccountNode(i, 1.0) for i in range(1, 10)]
    Tree = accounts.AccountTree()
    Tree.root = nodes[0]
    nodes[0]. left_child =nodes[1]
    nodes[1].right_sibling = nodes[2]
    nodes[2].right_sibling = nodes[3]
    nodes[3].right_sibling = nodes[4]
    nodes[1].left_child= nodes[5]
    nodes[5].right_sibling = nodes[6]
    nodes[4].left_child = nodes[7]
    nodes[6].left_child = nodes[8]

    if Tree.find(5) == nodes[4]:
        print("True")
    else:
        print(Tree.find(5).key)
        print("False")

main()