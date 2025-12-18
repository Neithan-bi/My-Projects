def issafe(grid,row,col,n):
    for i in range(row):
        if grid[i][col]==n:
            return False
    i,j = row -1, col -1
    while i>=0 and j>=0:
        if grid[i][j]==n:
            return False
        i-=1
        j-=1
    i,j = row -1, col +1
    while i>=0 and j<len(grid):
        if grid[i][j]==n:
            return False
        i-=1
        j+=1
    return True
def solve(grid,row,col):
    if row==len(grid):
        return True
    if col==len(grid):
        return solve(grid,row+1,0)
    if grid[row][col]!=0:
        return solve(grid,row,col+1)
    for n in range(1,10):
        if issafe(grid,row,col,n):
            grid[row][col]=n
            if solve(grid,row,col+1):
                return True
            grid[row][col]=0
    return False