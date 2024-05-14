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

int main() {

	return 0;
}