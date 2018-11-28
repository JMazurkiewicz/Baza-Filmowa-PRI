#include "Lists/StudioList.h"
#include <stdlib.h>

bool addStudio(StudioListNode* head, Studio studio) {

    if(findStudio(head, studio.name) != NULL) {
        return false;
    }

    StudioListNode* newHead = malloc(sizeof(StudioListNode));
    newHead->next = head;
    newHead->value = studio;

    return true;

}

Studio* findStudio(StudioListNode* head, StringView studioName) {

    for(StudioListNode* node = head; node != NULL; node = node->next) {

        if(hasStudioThisName(&node->value, studioName)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteStudio(StudioListNode* head, StringView studioName) {

    if(head != NULL) {
        if(hasStudioThisName(&head->value, studioName)) {
            free(head);
            return true;
        }
    } else {
        return false;
    }

    StudioListNode* previousElement = head;
    StudioListNode* currentElement = head->next;

    while(currentElement != NULL) {

        if(hasStudioThisName(&currentElement->value, studioName)) {
            previousElement->next = currentElement->next;
            free(currentElement);
            return true;
        }

    }

    return false;

}

void freeStudioListMemory(StudioListNode* head) {

    for(StudioListNode* node = head; node != NULL; ) {

        StudioListNode* const next = node->next;
        free(node);
        node = next;

    }

}
