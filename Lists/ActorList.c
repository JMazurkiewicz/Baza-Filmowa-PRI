#include "Lists/ActorList.h"
#include <stdlib.h>

void initActorList(ActorList* list) {
    list->head = NULL;
}

void freeActorList(ActorList* list) {

    for(ActorListNode* node = list->head; node != NULL; ) {
        ActorListNode* const next = node->next;
        free(node);
        node = next;
    }

    initActorList(list);

}

bool isActorListEmpty(const ActorList* list) {
    return list->head == NULL;
}

void addActor(ActorList* list, const Actor* actor) {

    ActorListNode* newHead = malloc(sizeof(ActorListNode));
    newHead->next = list->head;
    newHead->value = *actor;

    list->head = newHead;

}

Actor* findActor(ActorList* list, StringView name, StringView lastName) {

    for(ActorListNode* node = list->head; node != NULL; node = node->next) {

        if(hasActorTheseNames(&node->value, name, lastName)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteActor(ActorList* list, StringView name, StringView lastName) {

    ActorListNode* previousElement = (ActorListNode*)list;
    ActorListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(hasActorTheseNames(&currentElement->value, name, lastName)) {

            previousElement->next = currentElement->next;
            free(currentElement);
            return true;

        } else {

            previousElement = previousElement->next;
            currentElement = currentElement->next;

        }

    }

    return false;

}
