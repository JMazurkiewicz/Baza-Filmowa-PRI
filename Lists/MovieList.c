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


bool addMovie(MovieList* list, const Movie* movie) {

    if(findMovie(list, movie->title) != NULL) {
        return false;
    }

    MovieListNode* newHead = malloc(sizeof(MovieListNode));
    newHead->next = list->head;
    newHead->value = *movie;

    list->head = newHead;
    return true;

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
