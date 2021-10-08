#ifndef _BGPH_
#define _BGPH_

#define MAX_T 2 //maximum delay time
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#include "graph.h"

typedef struct event{
    int t;
    //Message info
    int sender;
    int receiver;
    //Route info
    int length;
    int dest;
    //Pointer to next event
    struct event *next;

} Event; 

Event* createEvent(int t, int sender, int receiver, int length, int dest);
void advertiseDestination(Node *dest, Event **calendar);
void insertEvent(Event **calendar, Event *message);
void removeEvent(Event **calendar);
void printCalendar(Event *calendar);
int newReceiveTime(int send_time, int prev_time);
void handleEvent(Graph *g, Event *message);

#endif