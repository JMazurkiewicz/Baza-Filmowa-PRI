#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/IO/MovieIO.h"
#include "Objects/Movie.h"
#include "Objects/Studio.h"
#include "Utility/MovieLimits.h"

void scanMoviesTitle(String title) {

    printString("Podaj tytul filmu: ");
    scanLine(title);
    trimWhitespace(title);

}

void scanMoviesIdentifier(Movie* movie) {
    scanMoviesTitle(movie->title);
}

void scanMoviesData(Movie* movie) {

    printString("Podaj imie i nazwisko rezysera: ");
    scanName(movie->director);

    printString("Podaj rok wydania filmu: ");
    movie->releaseYear =
        scanIntegerFromRange(MIN_MOVIES_RELEASE_YEAR, MAX_MOVIES_RELEASE_YEAR);

    printString("Podaj czas trwania filmu w minutach: ");
    movie->runningTime =
        scanIntegerFromRange(MIN_MOVIES_RUNNING_TIME, MAX_MOVIES_RUNNING_TIME);

    movie->studio = NULL;

}

void printMovie(const Movie* movie) {

    printf("Tytul: \"%s\"\n", movie->title);
    printf("Rezyser: %s\n", movie->director);
    printf("Rok premiery: %d\n", movie->releaseYear);
    printf("Czas trwania (w minutach): %d\n", movie->runningTime);

    if(movie->studio != NULL) {
        printf("Nazwa studia realizujacego film: %s\n", movie->studio->name);
    } else {
        puts("Studio w ktorym realizowano film (juz) nie istnieje...");
    }

}
