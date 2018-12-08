#pragma once

#include "Objects/Movie.h"
#include "Objects/Studio.h"
#include <stdbool.h>
#include "Utility/String.h"

typedef struct MovieListNode {

    struct MovieListNode* next;
    Movie value;

} MovieListNode;

typedef struct MovieList {

    MovieListNode* head;

} MovieList;


void initMovieList(MovieList* list);
void freeMovieList(MovieList* list);

bool isMovieListEmpty(const MovieList* list);

bool addMovie(MovieList* list, const Movie* movie);
const Movie* findMovie(const MovieList* list, StringView title);
bool deleteMovie(MovieList* list, StringView title);

void printMovieList(const MovieList* list);
