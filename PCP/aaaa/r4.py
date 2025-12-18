import sys

# Define the structure for a node in the binary tree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def build_tree_from_input(n, values, left_children, right_children):
    """
    Builds the binary tree structure from the three input arrays.
    
    This function uses a dictionary to map node values to TreeNode objects, 
    allowing us to easily connect parents to their children.
    """
    if n == 0:
        return None

    # 1. Create all TreeNode objects and map values to objects
    node_map = {}
    for val in values:
        node_map[val] = TreeNode(val)

    # The root node is the first element in the values array
    root = node_map[values[0]]
    
    # 2. Connect the nodes based on the child arrays
    for i in range(n):
        parent_val = values[i]
        left_val = left_children[i]
        right_val = right_children[i]
        
        parent_node = node_map[parent_val]
        
        # Connect left child
        if left_val != -1:
            parent_node.left = node_map[left_val]
            
        # Connect right child
        if right_val != -1:
            parent_node.right = node_map[right_val]
            
    return root

def calculate_height(root):
    """
    Computes the height of the binary tree recursively.
    Height = 1 + max(height of left subtree, height of right subtree).
    """
    # Base Case 1: If the tree is empty (or we are beyond a leaf), the height is 0.
    if root is None:
        return 0
    
    # Recursive Step: Find the height of the left and right subtrees
    left_height = calculate_height(root.left)
    right_height = calculate_height(root.right)
    
    # The height of the current tree is 1 (for the current node) plus the maximum
    # height of its two subtrees.
    return 1 + max(left_height, right_height)

def solve():
    """Reads input and runs the tree building and height calculation."""
    try:
        # Read all lines of input
        input_lines = sys.stdin.readlines()
        
        # Extract N, Node values, Left children, and Right children
        n = int(input_lines[0].strip())
        
        # If N=0, the tree is empty
        if n == 0:
            print(0)
            return

        values = list(map(int, input_lines[1].strip().split()))
        left_children = list(map(int, input_lines[2].strip().split()))
        right_children = list(map(int, input_lines[3].strip().split()))
        
    except:
        # Handle cases where input reading fails or N=0 but other lines are missing
        # print("Error reading input or tree is empty (N=0).", file=sys.stderr)
        return

    # 1. Build the Tree
    root = build_tree_from_input(n, values, left_children, right_children)
    
    # 2. Calculate Height Recursively
    height = calculate_height(root)
    
    # 3. Output Result
    print(height)

# Execute the solve function
solve()
