#include "Objects/Movie.h"

bool hasMovieThisTitle(const Movie* movie, StringView title) {

    return strCaseInsensitiveCompare(movie->title, title) == 0;

}
