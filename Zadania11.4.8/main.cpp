#include "Zadanie11.4.8.h"

int main() {
	srand(time(NULL));

	LOWL* list = lowl_create_random(6);
	lowl_print(list, "Zacatocny zoznam");

	printf("Current cursor: %f\n", list->potocny->data);
	printf("\n");

	printf("move cursor to right:\n");
	while (lowl_cur_step_right(list) == LOWL_OK) {
		printf("Current cursor: %f\n", list->potocny->data);
	}
	printf("\n");

	printf("move cursor to left:\n");
	while (lowl_cur_step_left(list) == LOWL_OK) {
		printf("Current cursor: %f\n", list->potocny->data);
	}
	printf("\n");

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