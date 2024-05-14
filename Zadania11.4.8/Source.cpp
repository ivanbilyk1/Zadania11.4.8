#include "stdio.h"
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

int main() {

	return 0;
}