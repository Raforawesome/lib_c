#include <stdio.h>
#include <stdlib.h>
#include "lib/structs/dynarray.h"

int main() {
	DynIntArr myarr = newintarr();
	iarrpush(&myarr, 3);
	iarrpush(&myarr, 4);
	iarrpush(&myarr, 5);

	printf("%d", *idx(&myarr, 2));
	return 0;
}