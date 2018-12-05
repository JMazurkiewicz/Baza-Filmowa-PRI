#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Movie.h"
#include "Utility/MovieLimits.h"

static bool isReleaseYearValid(int releaseYear);
static bool isRunningTimeValid(int runningTime);

bool hasMovieThisTitle(const Movie* movie, StringView title) {
    return strcmp(movie->title, title) == 0;
}

void scanMovie(Movie* movie) {

    printString("Podaj tytul filmu: ");
    getLine(movie->title);
    trimWhitespace(movie->title);

    printString("Podaj imie i nazwisko rezysera: ");
    scanName(movie->director);

    printString("Podaj rok wydania filmu: ");
    movie->releaseYear = scanIntegerIf(isReleaseYearValid);

    printString("Podaj czas trwania filmu w minutach: ");
    movie->runningTime = scanIntegerIf(isRunningTimeValid);

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

static bool isReleaseYearValid(int releaseYear) {
    return MIN_MOVIES_RELEASE_YEAR <= releaseYear && releaseYear <= MAX_MOVIES_RELEASE_YEAR;
}

static bool isRunningTimeValid(int runningTime) {
    return MIN_MOVIES_RUNNING_TIME <= runningTime && runningTime <= MAX_MOVIES_RUNNING_TIME;
}
