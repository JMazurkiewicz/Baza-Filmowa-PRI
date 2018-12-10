#pragma once

#include "Objects/Declarations.h"
#include "Objects/IO/MovieIO.h"
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
bool isMovieFromStudio(const Movie* movie, const Studio* studio);
