#pragma once

#include "Objects/Movie.h"
#include <stdbool.h>
#include "Utility/String.h"

typedef struct MovieListNode {

    struct MovieListNode* next;
    Movie value;

} MovieListNode;

bool addMovie(MovieListNode* head, Movie movie);
const Movie* findMovie(const MovieListNode* head, StringView title);
bool deleteMovie(MovieListNode* head, StringView title);

void freeMovieListMemory(MovieListNode* head);
