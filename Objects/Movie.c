#include "Objects/Movie.h"

bool hasMovieThisTitle(const Movie* movie, StringView title) {
    return strCaseInsensitiveCompare(movie->title, title) == 0;
}

bool isMovieFromStudio(const Movie* movie, const Studio* studio) {
    return movie->studio == studio;
}
