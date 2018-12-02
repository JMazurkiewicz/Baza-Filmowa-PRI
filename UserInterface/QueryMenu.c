#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdbool.h>
#include "UserInterface/Logo.h"
#include "UserInterface/QueryMenu.h"

typedef enum QueryMenuCommand {

    FETCH_ACTOR = '1',
    FETCH_MOVIE,
    FETCH_STUDIO

} QueryMenuCommand;

static void displayMenu();
static bool isInputValid(char input);
static void executeCommand(Database* database, QueryMenuCommand command);

void queryMenu(Database* database) {

    displayMenu();

    printString("Podaj numer operacji: ");
    const char input = readSingleCharIf(isInputValid);

    executeCommand(database, (QueryMenuCommand)input);

}

void displayMenu() {

    clearConsole();
    displayBigLogo();

    puts("O kim chcesz uzyskac wypis: ");
    puts("1) O aktorze [niedostepne]");
    puts("2) O filmie [niedostepne]");
    puts("3) O studiu nagraniowym [niedostepne]");

    newLine();

}

bool isInputValid(char input) {
    return input >= '1' && input <= '3';
}

void executeCommand(Database* database, QueryMenuCommand command) {

    switch(command) {

    case FETCH_ACTOR:
        // [niedostepne]
        break;

    case FETCH_MOVIE:
        // [niedostepne]
        break;

    case FETCH_STUDIO:
        // [niedostepne]
        break;

    }

}
