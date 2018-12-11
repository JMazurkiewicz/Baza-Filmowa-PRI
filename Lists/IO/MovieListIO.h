#pragma once

#include "Lists/Declarations.h"
#include "Objects/Declarations.h"

void scanMoviesOfStudio(MovieList* movies, const Studio* studio);

void printMovieList(const MovieList* list);
void printMoviesFromStudio(const MovieList* list, const Studio* studio);
