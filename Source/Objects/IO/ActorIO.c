#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Actor.h"

void scanActorsFullName(String name, String lastName) {
    printString("Podaj imie aktora: ");
    scanName(name);
    printString("Podaj nazwisko aktora: ");
    scanName(lastName);
}

void scanActorsIdentifiers(Actor* actor) {
    scanActorsFullName(actor->name, actor->lastName);
}

void scanActorsData(Actor* actor) {
    printString("Podaj rok urodzenia aktora: ");
    actor->yearOfBirth = scanBoundedInteger(MIN_ACTORS_YEAR_OF_BIRTH, MAX_ACTORS_YEAR_OF_BIRTH);
}

void printActorsFullName(const Actor* actor) {
    printf("%s %s", actor->name, actor->lastName);
}

void printActor(const Actor* actor) {
    printf("Imie: %s\n", actor->name);
    printf("Nazwisko: %s\n", actor->lastName);
    printf("Rok urodzenia: %d\n", actor->yearOfBirth);
}
