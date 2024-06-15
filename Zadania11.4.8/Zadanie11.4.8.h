#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LOWL_PROBLEM 0
#define LOWL_OK 1

typedef struct OWN { //OWN: štruktúra, ktorá predstavuje uzol zoznamu.
	float data;
	struct OWN* next;
}OWN;

typedef struct { //LOWL: štruktúra, ktorá predstavuje samotný zoznam.
	OWN* zac;
	OWN* potocny;
}LOWL;

char lowl_interpolate_linear(LOWL* list);//Vykoná lineárnu interpoláciu medzi každými dvoma uzlami zoznamu.
void lowl_print(LOWL* list, const char* msg);//Vytlačí položky zoznamu
OWN* lowl_insert_right(LOWL* list, float hodnota);
LOWL* lowl_create_empty(void);//Vytvorí prázdny zoznam a pridelí mu pamäť.
LOWL* lowl_create_random(unsigned int size);//Vytvorí zoznam s náhodnými hodnotami zadanej veľkosti.
void lowl_destroy(LOWL* list);//Vymaže zoznam a uvoľní pamäť.