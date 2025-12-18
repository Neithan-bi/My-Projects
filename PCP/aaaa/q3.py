import sys

def rotate_grid():
    """
    Reads grid dimensions, grid elements, and rotation count k.
    Calculates the effective rotations (k mod 4) and applies the 90° clockwise
    rotation using list comprehension k_prime times, then prints the result.
    """
    # Set up input reading from stdin for robustness
    input_data = sys.stdin.readlines()
    if len(input_data) < 4:
        # Check if basic input lines are present
        print("Error: Insufficient input provided. Need n, m, grid rows, and k.")
        return

    try:
        # Read n, m, and k from the input lines
        n = int(input_data[0].strip())
        m = int(input_data[1].strip())
        
        # Read the grid based on n rows
        grid = []
        for i in range(n):
            row = list(map(int, input_data[2 + i].strip().split()))
            if len(row) != m:
                print("Error: Grid row length mismatch based on column count m.")
                return
            grid.append(row)
            
        # Read k from the last line (index 2 + n)
        k = int(input_data[2 + n].strip())
    
    except Exception as e:
        # Handle parsing errors
        print(f"Error processing input data: {e}")
        return

    # --- Core Logic ---
    
    # 1. Calculate Effective Rotations
    # Since 4 rotations return to the original state, k only needs to be between 0 and 3.
    k_prime = k % 4 
    
    # 2. Perform Rotations
    # The loop executes k_prime times.
    for _ in range(k_prime):
        # The new grid has dimensions m x n.
        # The inner list comprehension creates the new columns (n elements).
        # The outer list comprehension creates the new rows (m elements).
        # Mapping: New Grid [i][j] = Old Grid [n - 1 - j][i]
        # where i is the new row index (0 to m-1) and j is the new column index (0 to n-1).
        
        grid = [[grid[n - 1 - j][i] for j in range(n)] for i in range(m)]
        
        # 3. Swap Dimensions
        # Update n and m for the next rotation iteration
        n, m = m, n 
        
    # 4. Print Final Grid
    for row in grid:
        print(*(row))

# Execute the function
# The original execution environment used direct input(), but this setup
# makes it functional for general input scenarios (like piped input).
# For use with standard `input()`, replace the sys.stdin logic with:
# n = int(input())
# m = int(input())
# grid = [list(map(int, input().split())) for _ in range(n)]
# k = int(input())
# k_prime = k % 4
# ... the rest of the loop and print logic ...

# For demonstration, we'll keep the self-contained functional structure:
# To run this code, you must provide the input sequence to standard input.
# Example Input:
# 2
# 3
# 1 2 3
# 4 5 6
# 1
# (Output will be: 4 1, 5 2, 6 3)