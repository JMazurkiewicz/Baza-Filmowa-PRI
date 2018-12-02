#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdbool.h>
#include "UserInterface/Logo.h"
#include "UserInterface/SortMenu.h"

typedef enum SortMenuCommand {

    SORT_ACTORS = '1',
    SORT_MOVIES,
    SORT_STUDIOS

} SortMenuCommand;

static void displayMenu();
static bool isInputValid(char input);
static void executeCommand(Database* database, SortMenuCommand command);

void sortMenu(Database* database) {

    displayMenu();

    printString("Podaj numer operacji: ");
    const char input = readSingleCharIf(isInputValid);

    executeCommand(database, (SortMenuCommand)input);

}

void displayMenu() {

    clearConsole();
    displayBigLogo();

    puts("Ktora tabele chcesz posortowac: ");
    puts("1) Aktorow [niedostepne]");
    puts("2) Filmow [niedostepne]");
    puts("3) Studiow nagraniowych [niedostepne]");

    newLine();

}

bool isInputValid(char input) {
    return input >= '1' && input <= '3';
}

void executeCommand(Database* database, SortMenuCommand command) {

    switch(command) {

    case SORT_ACTORS:
        // [not available]
        break;

    case SORT_MOVIES:
        // [not available]
        break;

    case SORT_STUDIOS:
        // [not available]
        break;

    }

}
