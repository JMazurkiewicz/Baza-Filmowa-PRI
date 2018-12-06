#pragma once

#include "Objects/Studio.h"
#include <stdbool.h>
#include "Utility/String.h"

typedef struct Movie {

    String title;
    String director;
    int releaseYear;
    int runningTime;

    Studio* studio;

} Movie;

bool hasMovieThisTitle(const Movie* movie, StringView title);

void scanMoviesTitle(String title);
void scanMovie(Movie* movie);

void printMovie(const Movie* movie);
