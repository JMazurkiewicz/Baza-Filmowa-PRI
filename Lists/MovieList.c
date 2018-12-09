#include "CommonIO/BasicIO.h"
#include "Lists/MovieList.h"
#include <stdlib.h>

void initMovieList(MovieList* list) {
    list->head = NULL;
}

void freeMovieList(MovieList* list) {

    for(MovieListNode* node = list->head; node != NULL; ) {
        MovieListNode* const next = node->next;
        free(node);
        node = next;
    }

    initMovieList(list);

}

bool isMovieListEmpty(const MovieList* list) {
    return list->head == NULL;
}

void addMovie(MovieList* list, const Movie* movie) {

    MovieListNode* newHead = malloc(sizeof(MovieListNode));
    newHead->next = list->head;
    newHead->value = *movie;

    list->head = newHead;

}

const Movie* findMovie(const MovieList* list, StringView title) {

    for(const MovieListNode* node = list->head; node != NULL; node = node->next) {

        if(hasMovieThisTitle(&node->value, title)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteMovie(MovieList* list, StringView title) {

    MovieListNode* previousElement = (MovieListNode*)list;
    MovieListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(hasMovieThisTitle(&currentElement->value, title)) {
            previousElement->next = currentElement->next;
            free(currentElement);
            return true;
        }

    }

    return false;

}

void printMovieList(const MovieList* list) {

    if(isMovieListEmpty(list)) {

        printString("Lista filmow jest pusta!\n");

    } else {

        puts("Lista filmow:");
        for(const MovieListNode* node = list->head; node != NULL; node = node->next) {
            printf("%s\n", node->value.title);
        }

    }

}
