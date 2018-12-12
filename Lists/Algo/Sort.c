#include "Lists/Algo/Sort.h"
#include <string.h>

static void* nextNode(void* node);
static const void* valueInNode(void* node, size_t valueOffset);
static void changeNext(void* node, void* newNext);
static void exchangeNextNodes(void* node1, void* node2);

void listSort(void* list, size_t valueOffset, Compare compare) {

	for(void* p = list; nextNode(p) != NULL; p = nextNode(p)) {

		for(void* q = nextNode(p); nextNode(q) != NULL; ) {

			const void* valueQ = valueInNode(nextNode(q), valueOffset);
			const void* valueP = valueInNode(nextNode(p), valueOffset);

			if(compare(valueQ, valueP)) {
				exchangeNextNodes(p, q);
			} else {
				q = nextNode(q);
			}

		}

	}

}

void* nextNode(void* node) {
	return (node == NULL) ? (NULL) : (*(void**)node);
}

const void* valueInNode(void* node, size_t valueOffset) {
	return ((unsigned char*)node) + valueOffset;
}

void changeNext(void* node, void* newNext) {
	memmove(node, &newNext, sizeof(void*));
}

void exchangeNextNodes(void* p, void* q) {

	void* const pNext = nextNode(p);
	void* const qNext = nextNode(q);

	changeNext(p, qNext);
	changeNext(q, pNext);

	void* temp = nextNode(pNext);
	changeNext(pNext, nextNode(qNext));
	changeNext(qNext, temp);

}
