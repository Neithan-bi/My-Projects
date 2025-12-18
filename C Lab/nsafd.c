/*
 Simple graph traversal in C: BFS and DFS using adjacency lists.

 Time complexity (both): O(V + E) using adjacency lists.
 Compile (Windows):
   gcc nsafd.c -o nsafd.exe
 Run:
   nsafd.exe

 Input format example:
 5 4 0
 0 1
 0 2
 1 3
 3 4
 (first line: V E directed_flag(0=undirected,1=directed))
 Then you'll be prompted for start vertex for BFS/DFS (-1 for full traversal).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node **createAdjList(int V) {
    Node **adj = (Node**)calloc(V, sizeof(Node*));
    return adj;
}

Node* newNode(int v) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->v = v;
    n->next = NULL;
    return n;
}

void addEdge(Node **adj, int u, int v, int directed) {
    Node *n = newNode(v);
    n->next = adj[u];
    adj[u] = n;
    if (!directed) {
        Node *m = newNode(u);
        m->next = adj[v];
        adj[v] = m;
    }
}

/* DFS (recursive) */
void dfsUtil(Node **adj, int u, int *visited) {
    visited[u] = 1;
    printf("%d ", u);
    for (Node *p = adj[u]; p; p = p->next)
        if (!visited[p->v])
            dfsUtil(adj, p->v, visited);
}

void dfs(Node **adj, int V, int start) {
    int *visited = (int*)calloc(V, sizeof(int));
    if (start >= 0 && start < V) {
        dfsUtil(adj, start, visited);
        /* finish disconnected components if any */
        for (int i = 0; i < V; ++i)
            if (!visited[i]) dfsUtil(adj, i, visited);
    } else { /* full traversal */
        for (int i = 0; i < V; ++i)
            if (!visited[i]) dfsUtil(adj, i, visited);
    }
    printf("\n");
    free(visited);
}

/* BFS using simple queue */
void bfs(Node **adj, int V, int start) {
    int *visited = (int*)calloc(V, sizeof(int));
    int *queue = (int*)malloc(V * sizeof(int));
    int front, rear;
    printf("BFS traversal: ");
    if (start >= 0 && start < V) {
        front = 0; rear = 0;
        visited[start] = 1;
        queue[rear++] = start;
        while (front < rear) {
            int u = queue[front++];
            printf("%d ", u);
            for (Node *p = adj[u]; p; p = p->next) {
                if (!visited[p->v]) {
                    visited[p->v] = 1;
                    queue[rear++] = p->v;
                }
            }
        }
        /* finish disconnected parts */
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
                while (front < rear) {
                    int u = queue[front++];
                    printf("%d ", u);
                    for (Node *p = adj[u]; p; p = p->next) {
                        if (!visited[p->v]) {
                            visited[p->v] = 1;
                            queue[rear++] = p->v;
                        }
                    }
                }
            }
        }
    } else { /* full traversal */
        for (int s = 0; s < V; ++s) {
            if (!visited[s]) {
                front = rear = 0;
                visited[s] = 1;
                queue[rear++] = s;
                while (front < rear) {
                    int u = queue[front++];
                    printf("%d ", u);
                    for (Node *p = adj[u]; p; p = p->next) {
                        if (!visited[p->v]) {
                            visited[p->v] = 1;
                            queue[rear++] = p->v;
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

/* free adjacency list */
void freeAdj(Node **adj, int V) {
    for (int i = 0; i < V; ++i) {
        Node *p = adj[i];
        while (p) {
            Node *tmp = p;
            p = p->next;
            free(tmp);
        }
    }
    free(adj);
}

int main(void) {
    int V, E, directed;
    if (scanf("%d %d %d", &V, &E, &directed) != 3) {
        fprintf(stderr, "Expected: V E directed_flag(0/1)\n");
        return 1;
    }
    if (V <= 0) { fprintf(stderr, "V must be > 0\n"); return 1; }

    Node **adj = createAdjList(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) {
            fprintf(stderr, "Expected edge: u v\n");
            freeAdj(adj, V);
            return 1;
        }
        if (u < 0 || u >= V || v < 0 || v >= V) {
            fprintf(stderr, "Vertex out of range (0..%d)\n", V-1);
            freeAdj(adj, V);
            return 1;
        }
        addEdge(adj, u, v, directed);
    }

    int start;
    printf("Enter start vertex for traversals (-1 for full graph): ");
    if (scanf("%d", &start) != 1) start = -1;

    printf("DFS traversal: ");
    dfs(adj, V, start);
    bfs(adj, V, start);

    freeAdj(adj, V);
    return 0;
}