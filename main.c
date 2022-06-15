#include <stdio.h>
#include <stdlib.h>
#include "lib/structs/dynarray.h"
#include "lib/types/string.h"

int main() {
	DynIntArr myarr = newintarr();
	myarr.push(&myarr, 3);
	myarr.push(&myarr, 4);
	myarr.push(&myarr, 5);

	printf("%d\n", myarr.idx(&myarr, 0));
	printf("%d\n", myarr.idx(&myarr, 1));
	printf("%d\n", myarr.idx(&myarr, 2));
	printf("%d\n", myarr.idx(&myarr, 3));
	return 0;
}