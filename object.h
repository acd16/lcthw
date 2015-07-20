#ifndef __object_h
#define __object_h

typedef enum {
		NORTH, SOUTH, EAST, WEST
}Dir;

typedef struct {
		char * desc;
		int (*init)(void * self);
		void (*describe)(void * self);
		void (*destroy)(void * self);
		void* (*move)(void *self, Dir dir);
		int (*attack)(void *self, int damage);
}Obj;

int Obj_init(void *self);
void Obj_destroy(void *self);
void Obj_describe(void *self);
void * Obj_move(void *self, Dir dir);
int Obj_attack(void *self, int damage);
void * Obj_new(size_t size, Obj proto, char *desc);

#define NEW(T, D) Obj_new(sizeof(T), T##Proto, D);
#define _(N) proto.N

#endif
