#include "Zadanie11.4.8.h"

int main() {
	srand(time(NULL));

	LOWL* list = lowl_create_random(6);
	lowl_print(list, "Zacatocny zoznam");

	char result = lowl_interpolate_linear(list);
	if (result == LOWL_PROBLEM) {
		printf("chyba pri interpolacii %c\n", result);
	}
	else if (result == LOWL_OK) {
		lowl_print(list, "final zoznam");
		printf("Current cursor: %f\n", list->potocny->data);
	}
	lowl_destroy(list);
	return 0;
}