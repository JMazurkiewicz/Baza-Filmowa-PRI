#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Movie.h"
#include "Utility/MovieLimits.h"

bool hasMovieThisTitle(const Movie* movie, StringView title) {
    return strcmp(movie->title, title) == 0;
}

void scanMoviesTitle(String title) {
    printString("Podaj tytul filmu: ");
    getLine(title);
    trimWhitespace(title);
}

void scanMovie(Movie* movie) {

    scanMoviesTitle(movie->title);

    printString("Podaj imie i nazwisko rezysera: ");
    scanName(movie->director);

    printString("Podaj rok wydania filmu: ");
    movie->releaseYear =
        scanIntegerFromRange(MIN_MOVIES_RELEASE_YEAR, MAX_MOVIES_RELEASE_YEAR);

    printString("Podaj czas trwania filmu w minutach: ");
    movie->runningTime =
        scanIntegerFromRange(MIN_MOVIES_RUNNING_TIME, MAX_MOVIES_RUNNING_TIME);

}

void printMovie(const Movie* movie) {

    printf("Tytul: %s\n", movie->title);
    printf("Rezyser: %s\n", movie->director);
    printf("Rok premiery: %d\n", movie->releaseYear);
    printf("Czas trwania (w minutach): %d", movie->runningTime);

    if(movie->studio != NULL) {
        printf("Nazwa studia realizujacego film: %s", movie->studio->name);
    } else {
        printf("Studio w ktorym realizowano film (juz) nie istnieje...");
    }
    newLine();

}
