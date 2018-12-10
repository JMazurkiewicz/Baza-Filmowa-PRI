#include "CommonIO/BasicIO.h"
#include "Lists/IO/MovieListIO.h"
#include "Lists/MovieList.h"

void printMovieList(const MovieList* list) {

    if(isMovieListEmpty(list)) {

        puts("Lista filmow jest pusta!");

    } else {

        puts("Lista filmow:");

        for(const MovieListNode* node = list->head; node != NULL; node = node->next) {

            printMoviesTitle(&node->value);
            newLine();

        }

    }

}

void printMoviesFromStudio(const MovieList* list, const Studio* studio) {

    bool noResults = true;

    for(const MovieListNode* node = list->head; node != NULL; node = node->next) {

        if(isMovieFromStudio(&node->value, studio)) {

            if(noResults) {
                noResults = false;
                puts("Lista filmow tego studia:");
            }

            printMoviesTitle(&node->value);

        }

    }

    if(noResults) {
        puts("Studio nie posiada filmow.");
    }

}
