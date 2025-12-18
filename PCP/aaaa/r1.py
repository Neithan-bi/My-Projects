def islP(grid):
    r=len(grid)
    c=len(grid[0])
    per=0
    for i in range(r):
        for j in range(c):
            if grid[i][j] ==1 :
                per+=4
                if i > 0 and grid[i-1][j]==1:
                    per-=2
                if j > 0 and grid[i][j-1]==1:
                    per-=2
    return per
rows = int(input())
grid = [list(map(int,input().split()))for _ in range(rows)]
print(islP(grid))