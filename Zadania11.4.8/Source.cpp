#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct OWN{ //OWN: štruktúra, ktorá predstavuje uzol zoznamu.
	float data;
	struct OWN* next;
}OWN;

typedef struct { //LOWL: štruktúra, ktorá predstavuje samotný zoznam.
	OWN* zac;
	OWN* potocny;
}LOWL;

char lowl_interpolate_linear(LOWL* list);//Vykoná lineárnu interpoláciu medzi každými dvoma uzlami zoznamu.
char lowl_cur_step_right(LOWL* list);
OWN* lowl_insert_right(LOWL* list, float val);
void lowl_print(LOWL* list, const char* msg);//Vytlačí položky zoznamu
LOWL* lowl_create_empty(void);//Vytvorí prázdny zoznam a pridelí mu pamäť.
LOWL* lowl_create_random(unsigned int size);//Vytvorí zoznam s náhodnými hodnotami zadanej veľkosti.
void lowl_destroi(LOWL* list);////Vymaže zoznam a uvoľní pamäť.

char lowl_interpolate_linear(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->zac->next == NULL) {
		return 'N';//nedostatok uzlov na interpoláciu
	}

	OWN* curr = list->zac;
	int step = 0;
	while (curr->next != NULL && curr != NULL) {
		float interpolated = (curr->data + curr->next->data) / 2.0f;

		OWN* newuzol = (OWN*)malloc(sizeof(OWN));
		if (newuzol ==NULL)
			return 'M';

		newuzol->data = interpolated;
		newuzol->next = curr->next;
		curr->next = newuzol;

		curr = newuzol->next;


		char ms[100];
		snprintf(ms, sizeof(ms), "Step interpolation %d", ++step);
		lowl_print(list, ms);
	}

	return 'U';//Uspeh
}

char lowl_cur_step_right(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->potocny == NULL || list->potocny->next == NULL) {
		return 'P';//kurzor je už na začiatku alebo je zoznam prázdny
	}

	list->potocny = list->potocny->next;

	return 'U';
}

OWN* lowl_insert_right(LOWL* list, float hodnota) {
	if (list == NULL)
	{
		return NULL;
	}

	OWN* newuzol = (OWN*)malloc(sizeof(OWN));
	if (newuzol == NULL) {
		return NULL;
	}

	newuzol->data = hodnota;
	newuzol->next = NULL;
	if (list->zac == NULL) {
		list->zac = newuzol;
		list->potocny = newuzol;
	}
	else {
		newuzol->next = list->potocny->next;
		list->potocny->next = newuzol;
	}
	return newuzol;
}

void lowl_print(LOWL* list, const char* ms) {
	if (list == NULL || list->zac == NULL) {
		printf("list je prazdny");
		return;
	}

	if (ms != NULL) {
		printf("%s: ", ms);
	}

	OWN* current_n = list->zac;

	while (current_n != NULL) {
			printf("%f ", current_n->data);

		current_n = current_n->next;
	}
	printf("\n");
}

LOWL* lowl_create_empty(void) {
	LOWL* newlist = (LOWL*)malloc(sizeof(LOWL));

	if (newlist == NULL) {
		return NULL;
	}
	newlist->zac = NULL;
	newlist->potocny = NULL;
	return newlist;
}

LOWL* lowl_create_random(unsigned int size) {
	LOWL* newlist = lowl_create_empty();
	if (newlist == NULL) {
		return NULL;
	}

	for (unsigned int i = 0; i < size; i++){
		float randomH = (float)rand() / RAND_MAX;
		lowl_insert_right(newlist, randomH);
		if (newlist->potocny == NULL) {
			newlist->potocny = newlist->zac;
		}
	}
	return newlist;
}

void lowl_destroi(LOWL* list) {
	if (list == NULL) {
		return;
	}
	OWN* current = list->zac;
	while (current != NULL) {
		OWN* temp = current;
		current = current->next;
		free(temp);
	}
	free(list);
}

int main() {
	srand(time(NULL));

	LOWL* list = lowl_create_random(6);
	lowl_print(list, "Zacatocny zoznam");

	char result = lowl_interpolate_linear(list);
	if (result != 'U') {
		printf("chyba pri interpolacii %c\n", result);
	}
	else {
		list->potocny = list->zac;
		while (list->potocny->next != NULL) {
			list->potocny = list->potocny->next;
		}
		lowl_print(list, "final zoznam");
	}

	lowl_destroi(list);
	return 0;
}