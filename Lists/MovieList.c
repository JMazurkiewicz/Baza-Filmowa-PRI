#include "Lists/MovieList.h"
#include <stdlib.h>

bool addMovie(MovieListNode* head, Movie movie) {

    if(findMovie(head, movie.title) != NULL) {
        return false;
    }

    MovieListNode* newHead = malloc(sizeof(MovieListNode));
    newHead->next = head;
    newHead->value = movie;

    return true;

}

Movie* findMovie(MovieListNode* head, StringView title) {

    for(MovieListNode* node = head; node != NULL; node = node->next) {

        if(hasMovieThisTitle(&node->value, title)) {
            return &node->value;
        }

    }

    return NULL;

}

bool deleteMovie(MovieListNode* head, StringView title) {

    if(head != NULL) {
        if(hasMovieThisTitle(&head->value, title)) {
            free(head);
            return true;
        }
    } else {
        return false;
    }

    MovieListNode* previousElement = head;
    MovieListNode* currentElement = head->next;

    while(currentElement != NULL) {

        if(hasMovieThisTitle(&currentElement->value, title)) {
            previousElement->next = currentElement->next;
            free(currentElement);
            return true;
        }

    }

    return false;

}

void freeMovieListMemory(MovieListNode* head) {

    for(MovieListNode* node = head; node != NULL; ) {

        MovieListNode* const next = node->next;
        free(node);
        node = next;

    }

}
