#include "Lists/ActorList.h"
#include <stdlib.h>

bool addActor(ActorListNode* head, Actor actor) {

    if(findActor(head, actor.name, actor.lastName) != NULL) {
        return false;
    }

    ActorListNode* newHead = malloc(sizeof(ActorListNode));
    newHead->next = head;
    newHead->value = actor;
    
    return true;

}

const Actor* findActor(const ActorListNode* head, StringView name, StringView lastName) {

    for(const ActorListNode* node = head; node != NULL; node = node->next) {

        if(hasActorTheseNames(&node->value, name, lastName)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteActor(ActorListNode* head, StringView name, StringView lastName) {

    if(head != NULL) {
        if(hasActorTheseNames(&head->value, name, lastName)) {
            free(head);
            return true;
        }
    } else {
        return false;
    }

    ActorListNode* previousElement = head;
    ActorListNode* currentElement = head->next;

    while(currentElement != NULL) {

        if(hasActorTheseNames(&currentElement->value, name, lastName)) {
            previousElement->next = currentElement->next;
            free(currentElement);
            return true;
        }

    }

    return false;

}

void freeActorListMemory(ActorListNode* head) {

    for(ActorListNode* node = head; node != NULL; ) {

        ActorListNode* const next = node->next;
        free(node);
        node = next;

    }

}
