#include <stdio.h>
#include <stdlib.h>
#include "lib/structs/dynarray.h"

int main() {
	DynIntArr myarr = newintarr();
	iarrpush(&myarr, 3);
	iarrpush(&myarr, 4);

	printf("%d", *(myarr.start));
	return 0;
}