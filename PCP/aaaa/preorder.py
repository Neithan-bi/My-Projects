tree_dict = {
'A' : ['B', 'C'],
'B' : ['D', 'E'],
'C' : ['F','G'],
'D' : [],
'E' : [],
'F' : []
}
def preorder(tree, node):
    print(node)
    for child in tree[node]:
        preorder(tree, child)
preorder(tree_dict, 'A')
