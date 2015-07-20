#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "19.h"


Obj MonsterProto = {
		.init = Monster_init,
		.attack = Monster_attack
};

int Monster_init(void * self){
		Monster * mon = self;
		mon->hitCount = 10;
		return 1;
}

int Monster_attack(void *self, int damage){
		Monster *mon = self;
		printf("You attack %s\n", mon->_(desc));
		mon->hitCount -= damage;
		if(mon->hitCount>0){
				printf("alive!\n");
				return 0;
		}else{
				printf("killed!\n");
				return 1;
		}
}

void *Room_move(void *self, Dir dir){
		Room * room = self;
		Room * next = NULL;

		if(dir == NORTH && room->north) {
				printf("north it is \n");
				next = room->north;
		}else if (dir == SOUTH && room->south) {
				printf("south it is \n");
				next = room->south;
		}else if (dir == EAST && room->east) {
				printf("east it is\n");
				next = room->east;
		}else if (dir == WEST && room->west) {
				printf("west it is \n");
				next = room->west;
		}else{
				printf("wrong dir\n");
				next = NULL;
		}
		return next;
}

int Room_attack(void *self, int damage)
{
		Room * room = self;
		Monster *mon = room->con;
		if(mon){
				mon->_(attack)(mon, damage);
				return 1;
		}else {
				printf("No monster!\n");
				return 0;
		}
}

Obj RoomProto = {
		.move = Room_move,
		.attack = Room_attack
};

void *Map_move(void *self, Dir dir){
		Map * map = self;
		Room * loc = map->loc;
		Room * next = loc->_(move)(loc, dir);

		if(next) {
				map->loc = next;
		}

		return next;
}

Obj MapProto = {
		.init = Map_init,
		.move = Map_move,
		.attack = Map_attack
};

int Map_attack(void *self, int damage){
		Map * map = self;
		Room * loc = map->loc;
		return loc->_(attack)(loc, damage);
}

int Map_init(void *self)
{
		Map * map = self;

		Room * hall = NEW(Room, "The hall");
		Room * throne= NEW(Room, "The throne");
		Room * arena= NEW(Room, "The arena");
		Room * kitchen= NEW(Room, "The kitchen");

		arena->con = NEW(Monster, "The evil one");

		hall->north = throne;

		throne->west = arena;
		throne->east = kitchen;
		throne->south = hall;

		arena->east = throne;
		kitchen->west = throne;

		map->start = hall;
		map->loc = hall;

		return 1;
}

int process_input(Map * map){
		printf("\n");
		char c = getchar();
		getchar();
		int damage = rand()%4;
		switch(c){
				case 'n':
						map->_(move)(map,NORTH);
						break;

				case 's':
						map->_(move)(map,SOUTH);
						break;

				case 'e':
						map->_(move)(map,EAST);
						break;

				case 'w':
						map->_(move)(map,WEST);
						break;

				case 'a':
						map->_(attack)(map,damage);
						break;

				case 'l':
						printf("Your options\n");
						if (map->loc->north) printf("North\n");
						if (map->loc->south) printf("South\n");
						if (map->loc->east) printf("East\n");
						if (map->loc->west) printf("West\n");
						map->_(move)(map,NORTH);
						break;

				case 'x':
						printf("GAME OVER\n");
						return 0;
						break;

				default:
						printf("unknown option\n");

		}
		return 1;
}

int main(int argc, char ** argv){
		srand(time(NULL));

		Map * map = NEW(Map, "The hall of the Minotaur.");

		printf("You enter -> ");
		map -> loc-> _(describe)(map->loc);

		while(process_input(map))

		return 0;
}
