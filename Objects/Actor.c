#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Actor.h"
#include "Utility/MovieLimits.h"

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName) {

    return strcmp(actor->name, name) == 0 &&
        strcmp(actor->lastName, lastName) == 0;

}

void scanActorsFullName(String name, String lastName) {

    printString("Podaj imie aktora: ");
    scanName(name);

    printString("Podaj nazwisko: ");
    scanName(lastName);

}

void scanActor(Actor* actor) {

    scanActorsFullName(actor->name, actor->lastName);

    printString("Podaj rok urodzenia aktora: ");
    actor->yearOfBirth =
        scanIntegerFromRange(MIN_ACTORS_YEAR_OF_BIRTH, MAX_ACTORS_YEAR_OF_BIRTH);

}

void printActor(const Actor* actor) {

    printf("Imie: %s\n", actor->name);
    printf("Nazwisko: %s\n", actor->lastName);
    printf("Rok urodzenia: %d\n", actor->yearOfBirth);

}
