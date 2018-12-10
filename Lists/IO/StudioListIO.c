#include "CommonIO/BasicIO.h"
#include "Lists/IO/StudioListIO.h"
#include "Lists/StudioList.h"

void printStudioList(const StudioList* list) {

    if(isStudioListEmpty(list)) {

        printString("Lista studiow nagraniowych jest pusta!\n");

    } else {

        puts("Lista studiow nagraniowych:");

        for(const StudioListNode* node = list->head; node != NULL; node = node->next) {

            printStudiosName(&node->value);
            newLine();

        }

    }

}
