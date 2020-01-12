#include <stdlib.h>
#include "queue.h"
#include "queuepriv.h"
#include<string.h>

Queue *Queue_init(void)
{
    Queue *q = calloc(1, sizeof(Queue));
    return q;
}

int Queue_enqueue(Queue *q, const char *id, const char *name)
{
    // implement this function
    if(strlen(id)>6)
    {
        return 0;
    }
    else
    {
    struct student *newstudent = malloc(sizeof(struct student));
    strcpy(newstudent->id,id);
    newstudent->name=malloc(strlen(name)+1);
    strcpy(newstudent->name,name);
    newstudent->next=NULL;
    if(q->first==NULL && q->last==NULL)
    {
    q->first=newstudent;
    q->last=q->first;
    return 1;
    }
    else
    {
    struct student *temp=q->first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        continue;
    }
    temp->next=newstudent;
    q->last=newstudent;
    return 1;
    }

}
}
int Queue_dequeue(Queue *q)
{
    if(q->first==NULL && q->last==NULL)
    {
        return 0;
    }

    else
    {
        if(q->first->next==NULL)
        {
            free(q->first->name);
            free(q->first);
            q->first=NULL;
            q->last=NULL;
            return 1;
        }
        else
        {
            struct student *new_head=q->first->next;
            struct student *head=q->first;
            free(head->name);
            free(head);
            q->first=new_head;
            return 1;

        }

    }



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

int Queue_drop(Queue *q, const char *id)
{
    // implement this function
        if(q->first==NULL && q->last==NULL)
        {
            return 0;
        }
        struct student *current=q->first;
        struct student *previous=NULL;
        while (strcmp(current->id,id)!=0)
        {
            if(current->next==NULL)
            {
                return 0;
            }

            else
            {
                previous=current;
                current=current->next;
                continue;
            }

        }
        // wrong
        if(current->next==NULL)
        {
                struct student *temp=q->first;
                struct student *last=temp;
                while(temp->next!=NULL)
                {
                    last=temp;
                    temp=temp->next;
                }
                free(last->next->name);
                free(last->next);
                last->next=NULL;
                return 1;
        } //wrong
        else
        {
            previous->next=current->next;
            free(current->name);
            free(current);
            return 1;
        }


}

void Queue_delete(Queue *q)
{
    if (q) {
        while(Queue_dequeue(q));
        free(q);
    }
}
