
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"        /* some integer queue functions */

/* linked list node for adjacency lists */

typedef struct list {
    int        v;    /* there is an edge to this vertex */
    struct list    *next;
} listnode;

typedef struct _graph {
    int        n;        /* number of vertices */
    listnode    **adjlists;    /* will be an array of lists */
    int        *marks;        /* array of Boolean */
} graph;

/* create an empty graph, knowing a priori how many vertices there will be */

void create_graph (graph *G, int n) {
    int    i;
    
    G->n = n;
    G->adjlists = malloc (n * sizeof (listnode *));
    G->marks = malloc (n * sizeof (int));
    for (i=0; i<n; i++) G->adjlists[i] = NULL;
}

/* insert a new edge to b into the adjacency list for a */

void insert_edge (graph *G, int a, int b) {
    listnode    *p;
    
    /* standard linked list insertion on adjlists[a] */
    
    p = malloc (sizeof (listnode));
    p->v = b;
    p->next = G->adjlists[a];
    G->adjlists[a] = p;
}

/* "search" the graph from vertex 'a' to all vertices reachable from 'a' */

void search (graph G, int a) {
    listnode    *p;
    int        i, b;
    
    G.marks[a] = 1;
    printf ("%i\n", a);
    for (p=G.adjlists[a]; p; p=p->next) {
        b = p->v;
        if (!(G.marks[b])) search (G, b);
    }
}

/* Depth First Search
 * search the graph beginning with the first vertex, until all vertices
 * have been visited
 */
void dfs (graph G) {
    int        a;
    
    /* set all marks to False */
    
    memset (G.marks, 0, G.n * sizeof (int));
    
    /* for all vertices, search from that vertex */
    
    for (a=0; a<G.n; a++)
        if (!(G.marks[a])) search (G, a);
}

void bfs (graph G) {
    queue        Q;
    int        a, b;
    listnode    *p;
    
    /* initialize queue */
    
    create_queue (&Q);
    
    /* set all marks to False */
    
    memset (G.marks, 0, G.n * sizeof (int));
    
    /* for each vertex in the graph */
    
    for (a=0; a<G.n; a++) {
        if (!(G.marks[a])) {
            enqueue (&Q, a);
            
            /* keep dequeueing until empty queue */
            
            while (!emptyq (Q)) {
                b = dequeue (&Q);
                if (!(G.marks[b])) {
                    
                    /* visit this unmarked vertex */
                    G.marks[b] = 1;
                    printf ("%i\n", b);
                    
                    /* enqueue all its neighbors */
                    
                    for (p=G.adjlists[b]; p; p=p->next)
                        enqueue (&Q, p->v);
                }
            }
        }
    }
}

int main () {
    graph    G;
    
    /* make the graph given in the lecture notes */
    
    create_graph (&G, 7);
    insert_edge (&G, 1, 2);
    insert_edge (&G, 1, 3);
    insert_edge (&G, 2, 4);
    insert_edge (&G, 2, 5);
    insert_edge (&G, 3, 1);
    insert_edge (&G, 3, 6);
    insert_edge (&G, 4, 6);
    insert_edge (&G, 4, 3);
    insert_edge (&G, 6, 5);
    printf ("Depth first Search\n");
    dfs (G);
    printf ("Breath first Search\n");
    bfs (G);
}

