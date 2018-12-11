#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Movie.h"
#include "Objects/Studio.h"
#include "Utility/MovieLimits.h"

void scanMoviesTitle(String title) {

    printString("Podaj tytul filmu: ");
    scanLine(title);
    strTrimWhitespace(title);

}

void scanMoviesIdentifier(Movie* movie) {
    scanMoviesTitle(movie->title);
}

void changeMoviesStudio(Movie* movie, const Studio* studio) {

    if(movie->studio != NULL) {

        printString("Film posiada juz przypisane studio, czy chcesz je zastapic (T/N): ");
        if(scanBoolean()) {
            movie->studio = studio;
        }

    } else {
        movie->studio = studio;
    }

}

void scanMoviesData(Movie* movie) {

    printString("Podaj imie i nazwisko rezysera: ");
    scanName(movie->director);

    printString("Podaj rok wydania filmu: ");
    movie->releaseYear = scanIntegerFromRange(MIN_MOVIES_RELEASE_YEAR, MAX_MOVIES_RELEASE_YEAR);

    printString("Podaj czas trwania filmu w minutach: ");
    movie->runningTime = scanIntegerFromRange(MIN_MOVIES_RUNNING_TIME, MAX_MOVIES_RUNNING_TIME);

    movie->studio = NULL;

}

void printMoviesTitle(const Movie* movie) {
    printf("\"%s\"", movie->title);
}

void printMovie(const Movie* movie) {

    printString("Tytul: ");
    printMoviesTitle(movie);
    newLine();

    printf("Rezyser: %s\n", movie->director);
    printf("Rok premiery: %d\n", movie->releaseYear);
    printf("Czas trwania (w minutach): %d\n", movie->runningTime);

    if(movie->studio != NULL) {

        printString("Nazwa studia realizujacego film: ");
        printStudiosName(movie->studio);
        newLine();

    } else {
        puts("Film nie posiada zapisanego studia.");
    }

}
