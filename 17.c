#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address{
	int id;
	int set;
	char name[512];
	char email[512];
}add;

typedef struct Database{
	add rows[100];
}db;

typedef struct Connection{
	FILE * file;
	db * dbase;
}conn;

void die(char * err){
	fprintf(stderr, "%s\n", err);
	exit(1);
}

void db_load(db * dbase, FILE * pFp){
	fread(dbase, sizeof(db), 1, pFp);
}

void print_add(add a){
	printf("%d %d %s %s\n", a.id, a.set, a.name, a.email);
}

conn * db_open(char * fname, char action){
	conn * db_conn = malloc(sizeof (conn));
	db_conn->dbase = malloc(sizeof(db));
	if (action == 'c')
		db_conn->file = fopen(fname, "w");
	else{
		db_conn->file = fopen(fname, "r+");
		if (db_conn->file)
			db_load(db_conn->dbase, db_conn->file);	
		}
	//printf("file %p", db_conn->file);
	return db_conn;		
	}

void db_create(conn * con){
	int i=0;
	for (i=0;i<100;i++)
		{
		con->dbase->rows[i].id = i;
		con->dbase->rows[i].set = 0;
		}
}

void db_write(conn * con){
	rewind(con->file);
	//printf("con file %p", con->dbase);
	fwrite(con->dbase, sizeof(db), 1, con->file);
	fflush(con->file);
}

void db_get(conn * con, int id){
	if(id>100)
		die("invalid id");
	db_load(con->dbase, con->file);
	print_add(con->dbase->rows[id]);
}

void db_set(conn * con, int id, char * name, char * email){
	add * a = &con->dbase->rows[id];
	a->set = 1;
	strcpy(a->name, name);
	strcpy(a->email, email);
	db_write(con);
}

void db_del(conn * con, int id){
	con->dbase->rows[id].set = 0;
	db_write(con);
}

void db_list(conn * con){
	int i=0;
	for (i=0;i<100;i++){
		if(con->dbase->rows[i].set == 1)
			printf("%d %s %s\n", i, con->dbase->rows[i].name, 
					con->dbase->rows[i].email);
	}
}

void db_close(conn *con){
	if(con->dbase)
		free(con->dbase);
	if(con->file)
		fclose(con->file);
	if(con)
		free(con);
	
}
	
int main(int argc, char ** argv){
	if(argc < 2)
		die("Too fews args");
	char * filename = argv[1];
	char op = argv[2][0];
	//printf("%c", op);
	conn * con = db_open(filename, op);
	switch(op){
	case 'c':{
		db_create(con);
		db_write(con);	
		break;
		}
	case 'g':{
		if(argc<4)
			die("need id for get operation");
		db_get(con, atoi(argv[3]));
		break;
		}
	case 's':{
		if(argc<6)
			die("need name and email");
		db_set(con, atoi(argv[3]), argv[4], argv[5]);
		break;
		}
	case 'd':{
		if(argc<4)
			die("need id for del operation");
		db_del(con, atoi(argv[3]));
		break;
		}
	case 'l':{
		db_list(con);
		break;
		}
	default:
		die("unknown option");
	}
	db_close(con);
	return 0;
}
