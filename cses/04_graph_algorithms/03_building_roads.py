import sys
sys.setrecursionlimit(2000000)
input = sys.stdin.readline
n, m = map(int, input().split())
E = [[] for _ in range(n + 1)]
vis = [False] * (n + 1)
for i in range(m):
    a, b = map(int, input().split())
    E[a].append(b)
    E[b].append(a)
 
def dfs(curr):
    vis[curr] = True
    for neigh in E[curr]:
        if vis[neigh]: continue
        dfs(neigh)
ans = []
dfs(1)
for i in range(2, n + 1):
    if vis[i]: continue
    dfs(i)
    ans.append([1, i])
print(len(ans))
for i in ans:
    print(i[0], i[1])