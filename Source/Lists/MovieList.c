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

Movie* findMovie(MovieList* list, StringView title) {

    for(MovieListNode* node = list->head; node != NULL; node = node->next) {

        if(hasMovieThisTitle(&node->value, title)) {
            return &node->value;
        }

    }

    return NULL;

}

void deleteMovie(MovieList* list, StringView title) {

    MovieListNode* previousElement = (MovieListNode*)list;
    MovieListNode* currentElement = list->head;

    while(currentElement != NULL) {

        if(hasMovieThisTitle(&currentElement->value, title)) {

            previousElement->next = currentElement->next;
            free(currentElement);
            break;

        } else {

            previousElement = previousElement->next;
            currentElement = currentElement->next;

        }

    }

}

void removeStudioFromMovieList(MovieList* list, const Studio* studio) {

    for(MovieListNode* node = list->head; node != NULL; node = node->next) {

        if(isMovieFromStudio(&node->value, studio)) {
            node->value.studio = NULL;
        }

    }

}
