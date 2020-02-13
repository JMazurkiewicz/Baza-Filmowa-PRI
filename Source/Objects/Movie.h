#pragma once

#include "Declarations.h"
#include <stdbool.h>
#include "Utility/String.h"

struct Movie {

    String title;
    String director;
    int runningTime;

    const Studio* studio;

};

#define MIN_MOVIES_RUNNING_TIME (1)
#define MAX_MOVIES_RUNNING_TIME (14400)

bool hasMovieThisTitle(const Movie* movie, StringView title);
bool isMovieFromStudio(const Movie* movie, const Studio* studio);

void scanMoviesTitle(String title);
void scanMoviesIdentifier(Movie* movie);
void scanMoviesData(Movie* movie);

void changeStudioOfMovie(Movie* movie, const Studio* studio);

void printMoviesTitle(const Movie* movie);
void printMovie(const Movie* movie);
