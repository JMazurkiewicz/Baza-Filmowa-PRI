#include "CommonIO/BasicIO.h"
#include "Lists/IO/MovieListIO.h"
#include "Lists/MovieList.h"

void printMovieList(const MovieList* list) {

    if(isMovieListEmpty(list)) {

        printString("Lista filmow jest pusta!\n");

    } else {

        puts("Lista filmow:");

        for(const MovieListNode* node = list->head; node != NULL; node = node->next) {
            printf("\"%s\"\n", node->value.title);
        }

    }

}
