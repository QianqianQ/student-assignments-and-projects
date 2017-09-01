#include <string.h>
#include <stdlib.h>
#include "queue.h"
#include "queuepriv.h"

Queue *Queue_init(void)
{
    Queue *q = calloc(1, sizeof(Queue));
    return q;
}

int Queue_enqueue(Queue *q, const char *id, const char *name)
{
    if (strlen(id) > 6) {
        return 0;
    }
    struct student *ns = calloc(1, sizeof(struct student));
    strcpy(ns->id, id);
    ns->name = malloc(strlen(name) + 1);
    strcpy(ns->name, name);

    if (q->last)
        q->last->next = ns;
    q->last = ns;

    if (!q->first)
        q->first = q->last;
    return 1;
}

char *Queue_firstID(Queue *q)
{
    if (q && q->first)
        return q->first->id;
    else
        return NULL;
}

char *Queue_firstName(Queue *q)
{
    if (q && q->first)
        return q->first->name;
    else
        return NULL;
}

int Queue_dequeue(Queue *q)
{
    if (q->first) {
        struct student *rq = q->first;
        q->first = q->first->next;
        free(rq->name);
        free(rq);
        if (!q->first)
            q->last = NULL;
        return 1;
    }
    return 0;
}

int Queue_drop(Queue *q, const char *id)
{
    struct student *s = q->first;
    struct student *p = NULL;
    while (s) {
        if (!strcmp(s->id, id)) {
            if (p)
                p->next = s->next;
            if (s == q->first)
                q->first = s->next;
            if (p && p->next == NULL)
                q->last = p;
            free(s->name);
            free(s);
            return 1;
        }
        p = s;
        s = s->next;
    }
    return 0;
}
