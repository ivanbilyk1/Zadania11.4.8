﻿#include "stdio.h"
#include "stdlib.h"

typedef struct OWN{
	float data;
	struct OWN* next;
}OWN;

typedef struct {
	OWN* zac;
	OWN* potocny;
}LOWL;

char lowl_interpolate_linear(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->zac->next == NULL) {
		return 'N';//nedostatok uzlov na interpoláciu
	}

	OWN* curr = list->zac;
	while (curr->next != NULL) {
		float interpolated = (curr->data + curr->next->data) / 2;

		OWN* newuzol = (OWN*)malloc(sizeof(OWN));

		newuzol->data = interpolated;
		newuzol->next = curr->next;
		curr->next = newuzol;

		curr = curr->next->next;
	}

	return 'U';//Uspeh
}

char lowl_cur_step_left(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->potocny == NULL || list->potocny == list->zac) {
		return 'P';//kurzor je už na začiatku alebo je zoznam prázdny
	}

	while (list->zac->next != list->potocny)
		list->zac = list->zac->next;

	list->potocny = list->zac;
	return 'U';
}

char lowl_cur_step_right(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->potocny == NULL || list->potocny->next == NULL) {
		return 'P';//kurzor je už na začiatku alebo je zoznam prázdny
	}

	list->potocny = list->potocny->next;

	return 'U';
}

OWN* lowl_insert_left(LOWL* list, float hodnota) {
	if (list == NULL)
	{
		return NULL;
	}

	OWN* newuzol = (OWN*)malloc(sizeof(OWN));
	if (newuzol == NULL) {
		return NULL;
	}

	newuzol->data = hodnota;
	if (list->zac == NULL) {
		list->zac = newuzol;
	}
	else if (list->potocny == list->zac) {
		newuzol->next = list->zac;
		list->zac = newuzol;
	}
	else {
		while (list->zac != list->potocny)
			list->zac = list->zac->next;

		newuzol->next = list->potocny;
		list->zac = newuzol;
	}
	return newuzol;
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
	if (list->zac == NULL) {
		list->zac = newuzol;
	}
	else {
		newuzol->next = list->potocny->next;
		list->potocny->next = newuzol;
	}
	return newuzol;
}

char lowl_delete(LOWL * list){
	if (list == NULL || list->zac == NULL) {
		return 'P';
	}

	if (list->potocny == list->zac) {
		OWN* temp = list->zac;
		list->zac = list->zac->next;
		free(temp);
		list->potocny = list->zac;
	}
	else {
		while (list->zac->next != list->potocny)
			list->zac = list->zac->next;
		list->zac->next = list->potocny->next;
		free(list->potocny);
		list->potocny = list->zac->next;
	}

	return 'U';
}

char lowl_print(LOWL* list) {
	if (list == NULL || list->zac == NULL) {
		printf("list je prazdny");
		return;
	}

	while (list->zac != NULL) {
		if (list->zac == list->potocny)
			printf("[%f] ", list->zac->data);
		else
			printf("%f ", list->zac->data);
		list->zac = list->zac->next;
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

	return 0;
}