#include "CommonIO/BasicIO.h"
#include "Lists/ActorList.h"
#include "Lists/IO/ActorListIO.h"

void printActorList(const ActorList* list) {

    if(isActorListEmpty(list)) {

        printString("Lista aktorow jest pusta!\n");

    } else {

        puts("Lista aktorow:");

        for(const ActorListNode* node = list->head; node != NULL; node = node->next) {
            printf("%s %s\n", node->value.name, node->value.lastName);
        }

    }

}
