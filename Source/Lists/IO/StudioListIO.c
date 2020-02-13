#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/StudioList.h"
#include "Utility/String.h"

static const StringView TRY_AGAIN = "Czy chcesz ponownie sprobowac dodac studio (T/N): ";

const Studio* scanStudioOfMovie(StudioList* studios) {

    printString("Czy chcesz dodac studio, w ktorym realizowano film (T/N): ");

    while(scanBoolean()) {

        String studioName;
        scanStudiosName(studioName);

        const Studio* const studio = findStudio(studios, studioName);

        if(studio == NULL) {
            puts("Takie studio nie istnieje w bazie!");
            printString(TRY_AGAIN);
        } else {
            return studio;
        }

    }

    return NULL;

}

void printStudioList(const StudioList* studios) {

    if(isStudioListEmpty(studios)) {

        printString("Lista studiow nagraniowych jest pusta!\n");

    } else {

        puts("Lista studiow nagraniowych:");

        for(const StudioListNode* node = studios->head; node != NULL; node = node->next) {

            printString("- ");
            printStudiosName(&node->value);
            newLine();

        }

    }

}
