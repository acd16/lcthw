#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

int Obj_init(void *self){
		return 1;
}

void Obj_destroy(void * self){
		Obj * obj = self;
		if (obj){
				if (obj->desc) free (obj->desc);
				free(obj);
		}
}

void Obj_describe(void *self){
		Obj obj = *(Obj *)self;
		printf("%s\n", obj.desc);
}

void *Obj_move(void * self, Dir dir){
		printf("You can't go in that direction\n");
		return NULL;
}

int Obj_attack(void * self, int damage){
		printf ("You can't attack yet\n");
		return 1;
}

void * Obj_new(size_t size, Obj obj, char * desc){
		if(!obj.init) obj.init = Obj_init;
		if(!obj.describe) obj.describe = Obj_describe;
		if(!obj.destroy) obj.destroy = Obj_destroy;
		if(!obj.attack) obj.attack = Obj_attack;
		if(!obj.move) obj.move = Obj_move;
		
		Obj * new_obj = malloc(size);
		*new_obj = obj;

		new_obj->desc = strdup(desc);

		if(!new_obj->init(new_obj)){
				new_obj->destroy(new_obj);
				return NULL;
		}else{
				return new_obj;
		}
}

