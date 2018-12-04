#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Submenus/InsertionMenu.h"

static void insertActorIntoDatabase(ActorListNode* list);
static bool isInputValid(int input);

static const MenuData INSERTION_MENU_DATA = {

    .content =
        "Wstaw:\n"
        "1) Nowego aktora [dostepne, bez dodawania rol]\n"
        "2) Nowy film [niedostepne]\n"
        "3) Nowe studio [niedostepne]\n"
        "4) Nowa role [niedostepne]\n",

    .inputValidator = isInputValid

};

void insertionMenu(Database* database) {

    switch(playMenu(&INSERTION_MENU_DATA)) {

    case 1:
        insertActorIntoDatabase(database->actors);
        break;

    case 2:
        // [niedostepne]
        break;

    case 3:
        // [niedostepne]
        break;

    case 4:
        // [niedostepne]
        break;

    }

}

bool isInputValid(int input) {
    return input >= 1 && input <= 4;
}

void insertActorIntoDatabase(ActorListNode* list) {
    Actor newActor;
    scanActor(&newActor);
    addActor(list, newActor);
}
