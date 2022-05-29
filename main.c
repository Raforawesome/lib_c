#include <stdio.h>
#include <stdlib.h>
#include "lib/structs/dynarray.h"

int main() {
	DynIntArr myarr = newintarr();
	iarrpush(&myarr, 3);
	iarrpush(&myarr, 4);
	iarrpush(&myarr, 5);

	printf("%d\n", *idx(&myarr, 0));
	printf("%d\n", *idx(&myarr, 1));
	printf("%d\n", *idx(&myarr, 2));
	printf("%d\n", *idx(&myarr, 3));
	return 0;
}