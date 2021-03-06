#if !defined(stdlib)
#include <stdlib.h>
#endif // stdlib
#if !defined(stdio)
#include <stdio.h>
#endif // stdio



#if !defined(DYNARRAY)
#define DYNARRAY


struct DynIntArr {
	int length;
	int filled;
	int* start;
	void (*push)(struct DynIntArr* arr, int num);
	int (*idx)(struct DynIntArr* arr, int idx);
	int (*find)(struct DynIntArr* arr, int target);
};
typedef struct DynIntArr DynIntArr;


void iarrpush(DynIntArr* arr, int num) {
	if (arr->filled < arr->length) {  // Check if capacity has been hit
		*(arr->start + arr->filled) = num;  // Set to next available address
		arr->filled += 1;  // Indicate we've used another slot
	} else {  // We've hit capacity;  Allocate more memory
		int* new_block = malloc(sizeof(int) * (arr->length + 10));  // Allocate a new block

		// Copy over old block
		for (int i = 0; i < arr->length; i++) {
			*(new_block + i) = *(arr->start + i);
		}

		*(new_block + arr->length) = num;  // Add our new variable to the block
		
		// De-allocate old block
		for (int i = 0; i < arr->length; i++) {
			free(arr->start + i);
		}

		arr->length += 10;  // We added 10 more slots
		arr->filled += 1;  // Filled 1 more slot
		arr->start = new_block;  // Replace old block with new block
	}
}

int diarridx(DynIntArr* arr, int idx) {
	return *(arr->start + idx);
}

int diarrfind(DynIntArr* arr, int target) {
	for (int i = 0; i < arr->filled; i++) {
		if (diarridx(arr, i) == target) {
			return i;
		}
	}
	return -1;
}

DynIntArr newintarr() {
	int* addr = (int*) malloc(sizeof(int));
	DynIntArr ret;
	ret.length = 1;
	ret.filled = 0;
	ret.start = addr;
	ret.push = &iarrpush;
	ret.idx = &diarridx;
	ret.find = &diarrfind;
	return ret;
}

// TODO:
// add search functions
// add swap method
// - add sort method
// add binary search method


#endif // DYNARRAY
