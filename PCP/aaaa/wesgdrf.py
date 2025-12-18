def solve(grid,x,y,n,visited,path):
    solve(grid,x,y,n,visited,path + 'U')
    solve(grid,x,y,n,visited,path + 'H')
    solve(grid,x,y,n,visited,path + 'L')
    visited[x][y] = False
n=int(input())
grid = []
for i in range(n):
    lst = list(map(int,input().split()))
    grid.append(lst)
visited = [[False for i in range(n)] for i in range(n)]
solve(grid,0,0,n,visited,"")

