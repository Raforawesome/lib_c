#if !defined(stdlib)
#include <stdlib.h>
#endif // stdlib


#if !defined(DYNARRAY)
#define DYNARRAY


struct DynIntArr {
	int length;
	int filled;
	int* start;
};

typedef struct DynIntArr DynIntArr;


DynIntArr newintarr() {
	int* addr = (int*) malloc(sizeof(int));
	DynIntArr ret;
	ret.length = 1;
	ret.filled = 0;
	ret.start = addr;
	return ret;
}

void iarrpush(DynIntArr* arr, int* num) {
	if (arr->filled < arr->length) {
		*(arr->start + arr->filled) = *num;
	} else {
		int* mem_block = malloc(sizeof(int) * (arr->length + 1));
		for (int i = 0; i < arr->length; i++) {
			*(mem_block + i) = *(arr->start + i);
		}
		*(mem_block + arr->length + 1) = *num;
		for (int i = 0; i < arr->length; i++) {
			free(arr->start + i);
		}
		arr->start = mem_block;
	}
}


#endif // DYNARRAY
