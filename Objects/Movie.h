#pragma once

#include "Objects/Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Movie {

    String title;
    String director;
    int releaseYear;
    int runningTime;

    const Studio* studio;

};

bool hasMovieThisTitle(const Movie* movie, StringView title);

void scanMoviesTitle(String title);
void scanMovie(Movie* movie);

void printMovie(const Movie* movie);
