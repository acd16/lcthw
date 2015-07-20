#ifndef __ex19_h
#define __ex19_h

#include "object.h"

typedef struct {
	Obj proto;
	int hitCount;
}Monster;

int Monster_attack(void *self, int damage);
int Monster_init(void *self);

typedef struct room{
		Obj proto;
		Monster *con;
		struct room * north;
		struct room * south;
		struct room * east;
		struct room * west;
}Room;


void *Room_move(void *self, Dir dir);
int Room_attack(void *self, int damage);
int Room_init(void *self);

typedef struct {
		Obj proto;
		Room * start;
		Room * loc;
}Map;

void *Map_move(void * self, Dir dir);
int Map_attack(void * self, int damage);
int Map_init(void *self);

#endif
