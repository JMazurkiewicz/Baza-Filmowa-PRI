#include "Lists/Algo/Sort.h"

//static void* nextNode(void* node);
//static const void* valueOf(const void* node, size_t valueOffset);
//static void exchangeNextNodes(void* node1, void* node2);

void listSort(void* list, size_t valueOffset, SortCompare compare) {



}

void* nextNode(void* node) {
    return *(void**)node;
}

const void* valueOf(const void* node, size_t valueOffset) {
    return ((unsigned char*)node) + valueOffset;
}

void exchangeNextNodes(void* node1, void* node2) {



}
