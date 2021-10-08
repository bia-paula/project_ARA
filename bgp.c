#include "bgp.h"
#include <stdlib.h>
#include <stdio.h>

Event* createEvent(int t, int sender, int receiver, int length, int dest){
    Event *e = malloc(sizeof(Event));

    e->t = t;
    e->sender = sender;
    e->receiver = receiver;
    e->length = length;
    e->dest = dest;

    return e;
}

void advertiseDestination(Node *dest, Event **calendar){
    Edge *out = dest->adjList;
    int t=0, len=0;
    Event *e;

    while (out!=NULL)
    {
        e = createEvent(newReceiveTime(t, 0), dest->head, out->tail, len, dest->head);
        insertEvent(calendar, e);
        out = out->next;
    }
}

void insertEvent(Event **calendar, Event *message){
    Event *aux_prev, *aux_next;

    //Message goes first in calendar
    if (*calendar == NULL || message->t < (*calendar)->t){
        message->next = (*calendar);
        (*calendar) = message;
        return;
    }

    aux_prev = (*calendar);
    aux_next = (*calendar)->next;

    while(1){
        if(aux_next == NULL || message->t < aux_next->t){
            message->next = aux_next;
            aux_prev->next = message;
            break;
        }
        aux_prev = aux_prev->next;
        aux_next = aux_next->next;
    }
}

void removeEvent(Event **calendar){
    Event *aux = *calendar;

    *calendar = (*calendar)->next;
    free(aux);
}

void printCalendar(Event *calendar){
    Event *aux = calendar;

    while(aux!=NULL){
        printf("\nTime: %d\n", aux->t);
        printf("From: %d To: %d\n", aux->sender, aux->receiver);
        printf("Route to %d len: %d\n", aux->dest, aux->length);
        aux = aux->next;
    }

}

int newReceiveTime(int send_time, int prev_time){
    int r = rand()%(MAX_T + 1);

    return MAX(send_time + 1 + r, prev_time);
}

void handleEvent(Graph *g, Event *message){
    return;
}