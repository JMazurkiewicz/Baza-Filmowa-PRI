#include "CommonIO/BasicIO.h"
#include "Lists/ActorList.h"
#include "Lists/IO/ActorListIO.h"

void printActorList(const ActorList* list) {

    if(isActorListEmpty(list)) {

        puts("Lista aktorow jest pusta!");

    } else {

        puts("Lista aktorow:");

        for(const ActorListNode* node = list->head; node != NULL; node = node->next) {

            printString("- ");
            printActorsFullName(&node->value);
            newLine();

        }

    }

}
