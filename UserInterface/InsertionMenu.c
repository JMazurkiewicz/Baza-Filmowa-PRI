#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdbool.h>
#include "UserInterface/InsertionMenu.h"
#include "UserInterface/Logo.h"

typedef enum InsertionMenuCommand {

    INSERT_NEW_ACTOR = '1',
    INSERT_NEW_MOVIE,
    INSERT_NEW_STUDIO,
    INSERT_NEW_ROLE

} InsertionMenuCommand;

static void displayMenu();
static bool isInputValid(char input);
static void executeCommand(Database* database, InsertionMenuCommand command);

static void insertActorIntoDatabse(ActorListNode* list);

void insertionMenu(Database* database) {

    displayMenu();

    printString("Podaj numer operacji: ");
    const char input = scanCharIf(isInputValid);

    executeCommand(database, (InsertionMenuCommand)input);

}

void displayMenu() {

    clearConsole();
    displayLogo();

    puts("Wstaw: ");
    puts("1) Nowego aktora [dostepne, bez dodawania rol]");
    puts("2) Nowy film [niedostepne]");
    puts("3) Nowe studio [niedostepne]");
    puts("4) Nowa role [niedostepne]");

    newLine();

}

bool isInputValid(char input) {
    return input >= '1' && input <= '4';
}

void executeCommand(Database* database, InsertionMenuCommand command) {

    switch(command) {

    case INSERT_NEW_ACTOR:
        insertActorIntoDatabse(database->actors);
        break;

    case INSERT_NEW_MOVIE:
        // [niedostepne]
        break;

    case INSERT_NEW_STUDIO:
        // [niedostepne]
        break;

    case INSERT_NEW_ROLE:
        // [niedostepne]
        break;

    }

}

void insertActorIntoDatabse(ActorListNode* list) {
    Actor newActor;
    scanActor(&newActor);
    addActor(list, newActor);
}
