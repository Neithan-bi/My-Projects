tree = (5,
        (4,
            (11,
                (7, None, None),
                (2, None, None)
            ),
            None
        ),
        (8,
            (13, None, None),
            (4,
                None,
                (1, None, None)
            )
        )
    )
def has_path_sum(node,target_sum):
    if Node is None:
        return False
    value = node[0]
    if node[1] is None and node[2] is None:
        return value == target_sum
    remaining_sum = target_sum - value
    return (has_path_sum(node[1], remaining_sum) or
            has_path_sum(node[2], remaining_sum)) 
     
target = int(input("Enter the target sum: "))
if has_path_sum(tree, target):
    print("There exists a root-to-leaf path with the given sum.")   
else:
    print("No root-to-leaf path with the given sum exists.")