#include "Lists/StudioList.h"
#include <stdlib.h>

void initStudioList(StudioList* list) {
    list->head = NULL;
}

void freeStudioList(StudioList* list) {

    for(StudioListNode* node = list->head; node != NULL; ) {
        StudioListNode* const next = node->next;
        free(node);
        node = next;
    }

    initStudioList(list);

}

bool isStudioListEmpty(const StudioList* list) {
    return list->head == NULL;
}

void addStudio(StudioList* list, const Studio* studio) {

    StudioListNode* newHead = malloc(sizeof(StudioListNode));
    newHead->next = list->head;
    newHead->value = *studio;

    list->head = newHead;

}

Studio* findStudio(StudioList* list, StringView studioName) {

    for(StudioListNode* node = list->head; node != NULL; node = node->next) {
        if(hasStudioThisName(&node->value, studioName)) {
            return &node->value;
        }
    }

    return NULL;

}

void deleteStudio(StudioList* list, StringView studioName) {

    StudioListNode* previousElement = (StudioListNode*)list;
    StudioListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(hasStudioThisName(&currentElement->value, studioName)) {
            previousElement->next = currentElement->next;
            free(currentElement);
            break;
        } else {
            previousElement = previousElement->next;
            currentElement = currentElement->next;
        }

    }

}
