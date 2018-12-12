#pragma once

#include "Objects/Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Movie {

    String title;
    String director;
    int runningTime;

    const Studio* studio;

};

bool hasMovieThisTitle(const Movie* movie, StringView title);
bool isMovieFromStudio(const Movie* movie, const Studio* studio);

void scanMoviesTitle(String title);
void scanMoviesIdentifier(Movie* movie);
void scanMoviesData(Movie* movie);

void changeMoviesStudio(Movie* movie, const Studio* studio);

void printMoviesTitle(const Movie* movie);
void printMovie(const Movie* movie);
