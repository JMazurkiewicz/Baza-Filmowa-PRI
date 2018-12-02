#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include "IO/NameInput.h"
#include "Objects/Actor.h"

const int MIN_ACTORS_YEAR_OF_BIRTH = 1900;
const int MAX_ACTORS_YEAR_OF_BIRTH = 2018;

static bool isYearOfBirthValid(int yearOfBirth);

bool hasActorTheseNames(const Actor* actor, StringView name, StringView lastName) {
    return strcmp(actor->name, name) == 0 && strcmp(actor->lastName, lastName) == 0;
}

void readActor(Actor* actor) {

    printString("Podaj imie aktora (zgodne z zasadami wprowadzania danych): ");
    readName(actor->name);

    printString("Podaj nazwisko: ");
    readName(actor->lastName);

    printString("Podaj rok urodzenia aktora: ");
    actor->yearOfBirth = readIntegerIf(isYearOfBirthValid);

}

bool isYearOfBirthValid(int yearOfBirth) {
    return yearOfBirth >= MIN_ACTORS_YEAR_OF_BIRTH && yearOfBirth <= MAX_ACTORS_YEAR_OF_BIRTH;
}
