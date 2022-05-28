#include <stdlib.h>
#include <stdio.h>

int main() {
	int* sum = (int*) malloc(sizeof(int));
	*sum = 0;

	for (int i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) {
			*sum += i;
		}
	}

	printf("Sum: %d", *sum);

	free(sum);
	return 0;
}