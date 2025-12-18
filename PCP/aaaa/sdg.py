# Beginner-style simple matrix program: input, display, transpose, reverse columns

def input_matrix(r, c):
    mat = []
    for i in range(r):
        parts = input(f"Row {i+1} (enter {c} numbers separated by space): ").split()
        nums = [int(x) for x in parts[:c]] + [0] * max(0, c - len(parts))
        mat.append(nums)
    return mat

def print_matrix(mat):
    for row in mat:
        print(" ".join(map(str, row)))

def transpose(mat):
    return [list(row) for row in zip(*mat)] if mat else []

def reverse_columns(mat):
    return [row[::-1] for row in mat]

if __name__ == "__main__":
    r = int(input("Number of rows: "))
    c = int(input("Number of columns: "))
    matrix = input_matrix(r, c)

    print("\nOriginal matrix:")
    print_matrix(matrix)

    print("\nTransposed matrix:")
    print_matrix(transpose(matrix))

    print("\nMatrix with columns reversed:")
    print_matrix(reverse_columns(matrix))
