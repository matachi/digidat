#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct qstruct {
    struct qelemstruct *head;
    int length;
};
struct qiteratorstruct {
    struct qstruct *q;
    struct qelemstruct *curr;
};
struct qelemstruct {
    struct qelemstruct *next, *prev;
    int prio;
    DATA *data;
};
typedef struct qstruct *Queue;
typedef struct qiteratorstruct *Iterator;
typedef struct qelemstruct *Element;

/************************************************************
 * Queue
 */
Queue new_queue() {
    Queue q = (Queue) malloc(sizeof(struct qstruct));
    Element e = (Element) malloc(sizeof(struct qelemstruct));
    q->head = e;
    q->length = 0;
    e->next = e->prev = e;
    e->prio = 0;
    e->data = NULL;
    return q;
}
void delete_queue(Queue q) {
    free(q);
}
void clear(Queue q) {
    while (q->length > 0) {
        remove_first(q);
    }
}
int size(Queue q) {
    return q->length;
}
void add(Queue q, int priority, DATA *d) {
    Element e = q->head;
    for (int i = 0; i < q->length; ++i) {
        if (priority <= e->next->prio) {
            e = e->next;
        }
    }
    Element newE = (Element) malloc(sizeof(struct qelemstruct));
    newE->data = d;
    newE->next = e->next;
    newE->prev = e;
    newE->prio = priority;
    e->next = newE;
    q->length += 1;
}
DATA *get_first(Queue q) {
    return q->head->next->data;
}
void remove_first(Queue q) {
    remove_element(q, q->head->next);
}
void remove_element(Queue q, Element e) {
    Element e2 = q->head->next;
    for (int i = 0; i < q->length; ++i) {
        if (e2 == e) {
            Element prevE = e2->prev;
            Element nextE = e2->next;
            prevE->next = nextE;
            nextE->prev = prevE;
            //free(e2->data);
            //free(e2);
            q->length -= 1;
        }
        e2 = e2->next;
    }
}

/************************************************************
 * Iterator
 */
Iterator new_iterator(Queue q) {
    Iterator i = (Iterator) malloc(sizeof(struct qiteratorstruct));
    i->q = q;
    i->curr = q->head->next;
    return i;
}
void delete_iterator(Iterator it) {
    free(it);
}
void go_to_first(Iterator it) {
    it->curr = it->q->head->next;
}
void go_to_last(Iterator it) {
    it->curr = it->q->head->prev;
}
void go_to_next(Iterator it) {
    if (it->curr != it->q->head) {
        it->curr = it->curr->next;
    }
}
void go_to_previous(Iterator it) {
    if (it->curr != it->q->head) {
        it->curr = it->curr->prev;
    }
}
DATA *get_current(Iterator it) {
    //int *i = malloc(sizeof(int));
    //*i = 0;
    //return (it->curr == i->q->head) ? 0 :it->curr->data;
    return it->curr->data;
}
int is_valid(Iterator it) {
    //return (it->curr->data == NULL) ? 0 : 1;
    return (it->curr == it->q->head) ? 0 : 1;
}

void change_current(Iterator it, DATA *d) {
    if (it->curr != it->q->head) {
        it->curr->data = d;
    }
}
void remove_current(Iterator it) {
    Element next = it->curr->next;
    if (it->curr != it->q->head) {
        remove_element(it->q, it->curr);
    }
    it->curr = next;
}
void find(Iterator it, DATA *d) {
    Element e = it->q->head->next;
    for (int i = 0; i <= it->q->length; ++i) {
        if (e->data == d) {
            break;
        }
        e = e->next;
    }
    it->curr = e;
}
