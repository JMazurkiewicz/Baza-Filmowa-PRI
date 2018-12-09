#pragma once

#include "Objects/Declarations.h"
#include "Utility/String.h"

void scanMoviesTitle(String title);

void scanMoviesIdentifier(Movie* movie);
void scanMoviesData(Movie* movie);

void printMovie(const Movie* movie);
