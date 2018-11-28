#include "Objects/Movie.h"

bool hasMovieThisTitle(const Movie* movie, StringView title) {
    return strcmp(movie->title, title) == 0;
}
