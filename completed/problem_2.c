#include <stdio.h>
#include <stdlib.h>

typedef enum {
	false,
	true
} bool;

int fib(int n) {
	if (n < 2) { return n; }
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int* sum = (int*) malloc(sizeof(int) * 2);
	int* i = sum + 1; 

	*sum = 0;
	*i = 1;

	while (true == true) {
		int fibres = fib(*i);
		if (fibres > 4000000) {
			break;
		}
		if (fibres % 2 == 0) {
			*sum += fibres; 
		}
		*i += 1;
	}
	printf("Result: %d", *sum);
	return 0;
}