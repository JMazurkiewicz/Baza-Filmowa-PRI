#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Lists/MovieList.h"

static void setMoviesStudio(Movie* movie, const Studio* studio);
static void printMovieOnList(const Movie* movie);

void scanMoviesOfStudio(MovieList* movies, const Studio* studio) {

    printString("Czy chcesz dodac film do studia (T/N): ");

    while(scanBoolean()) {

        String title;
        scanMoviesTitle(title);

        Movie* const movie = findMovie(movies, title);

        if(movie == NULL) {

            puts("\aTaki film nie istnieje w bazie!");
            printString("Czy chcesz sprobowac ponownie dodac film do studia (T/N): ");

        } else {

            setMoviesStudio(movie, studio);
            printString("Czy chcesz dodac kolejny film do studia (T/N): ");

        }

    }

}

void setMoviesStudio(Movie* movie, const Studio* studio) {

    if(movie->studio != NULL) {

        printString("Film posiada juz przypisane studio, czy chcesz je zastapic (T/N): ");
        if(scanBoolean()) {
            movie->studio = studio;
        }

    } else {
        movie->studio = studio;
    }

}

void printMovieList(const MovieList* list) {

    if(isMovieListEmpty(list)) {

        puts("Lista filmow jest pusta!");

    } else {

        puts("Lista filmow:");

        for(const MovieListNode* node = list->head; node != NULL; node = node->next) {
            printMovieOnList(&node->value);
        }

    }

}

void printMoviesFromStudio(const MovieList* list, const Studio* studio) {

    bool noResults = true;

    for(const MovieListNode* node = list->head; node != NULL; node = node->next) {

        if(isMovieFromStudio(&node->value, studio)) {

            if(noResults) {
                noResults = false;
                puts("Lista filmow tego studia:");
            }

            printMovieOnList(&node->value);

        }

    }

    if(noResults) {
        puts("Studio nie posiada filmow.");
    }

}

void printMovieOnList(const Movie* movie) {

    printString("- ");
    printMoviesTitle(movie);
    newLine();

}
