#include "Zadanie11.4.8.h"

char lowl_interpolate_linear(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->zac->next == NULL) {
		return LOWL_PROBLEM;//nedostatok uzlov na interpoláciu
	}

	OWN* curr = list->zac;
	OWN* original_potocny = list->potocny;
	int step = 0;
	while (curr->next != NULL && curr != NULL) {
		float interpolated = (curr->data + curr->next->data) / 2.0f;
		list->potocny = curr;
		lowl_insert_right(list, interpolated);
		curr = list->potocny->next->next;
	}

	list->potocny = original_potocny;
	return LOWL_OK;
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

char lowl_cur_step_right(LOWL* list) {
	if (list == NULL || list->zac == NULL || list->potocny == NULL || list->potocny->next == NULL) {
		return LOWL_PROBLEM;
	}

	list->potocny = list->potocny->next;
	return LOWL_OK;
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

void lowl_destroy(LOWL* list) {
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