#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "CommonIO/NameInput.h"
#include "Objects/Actor.h"
#include "Utility/MovieLimits.h"

static bool isYearOfBirthValid(int yearOfBirth);

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName) {
    return strcmp(actor->name, name) == 0 && strcmp(actor->lastName, lastName) == 0;
}

void scanActor(Actor* actor) {

    printString("Podaj imie aktora: ");
    scanName(actor->name);

    printString("Podaj nazwisko: ");
    scanName(actor->lastName);

    printString("Podaj rok urodzenia aktora: ");
    actor->yearOfBirth = scanIntegerIf(isYearOfBirthValid);

}

void printActor(const Actor* actor) {
    printf("Imie: %s\n", actor->name);
    printf("Nazwisko: %s\n", actor->lastName);
    printf("Rok urodzenia: %s\n", actor->yearOfBirth);
}

bool isYearOfBirthValid(int yearOfBirth) {
    return yearOfBirth >= MIN_ACTORS_YEAR_OF_BIRTH && yearOfBirth <= MAX_ACTORS_YEAR_OF_BIRTH;
}
