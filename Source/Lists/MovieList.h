#pragma once

#include "Declarations.h"
#include "Objects/Movie.h"
#include <stdbool.h>
#include "Utility/String.h"

struct MovieListNode {
    MovieListNode* next;
    Movie value;
};

struct MovieList {
    MovieListNode* head;
};

void initMovieList(MovieList* list);
void freeMovieList(MovieList* list);

bool isMovieListEmpty(const MovieList* list);

void addMovie(MovieList* list, const Movie* movie);
Movie* findMovie(MovieList* list, StringView title);
void deleteMovie(MovieList* list, StringView title);
void removeStudioFromMovieList(MovieList* list, const Studio* studio);

void scanMoviesOfStudio(MovieList* movies, const Studio* studio);

void printMovieList(const MovieList* list);
void printMoviesFromStudio(const MovieList* list, const Studio* studio);
