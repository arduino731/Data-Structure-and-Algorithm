/* size of queue */

#define MAXQ    100

/* queue ADT type */

typedef struct _queue {
    int    head, tail;
    float    v[MAXQ];
} queue;

/* make a queue; head = tail = 0 */

void create_queue (queue *Q) {
    Q->head = 0;
    Q->tail = 0;
}

/* put k onto queue Q */
void enqueue (queue *Q, float k) {
    Q->v[Q->tail] = k;
    Q->tail++;
    Q->tail %= MAXQ;
    if (Q->tail == Q->head) {
        fprintf (stderr, "queue full!\n");
        exit (1);
    }
}

/* remove from queue and return */

float dequeue (queue *Q) {
    float    r;
    
    if (Q->head == Q->tail) {
        fprintf (stderr, "queue empty!\n");
        exit (1);
    }
    r = Q->v[Q->head];
    Q->head++;
    Q->head %= MAXQ;
    return r;
}

/* return true iff queue is empty */

int emptyq (queue Q) {
    return Q.head == Q.tail;
}

