rows = int(input())  # always 3
cols = int(input())
matrix = [list(map(int, input().split())) for _ in range(rows)]
top, bottom, left, right = 0, rows - 1, 0, cols - 1
result = []

while left <= right and top <= bottom:
    result.extend(matrix[top][left:right+1])
    top += 1
    if top > bottom: break
    for i in range(top, bottom + 1):
        result.append(matrix[i][right])
    right -= 1
    if left > right: break
    result.extend(matrix[bottom][right:left-1:-1])
    bottom -= 1
    for i in range(bottom, top - 1, -1):
        result.append(matrix[i][left])
    left += 1
print(" ".join(map(str, result)))