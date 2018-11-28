#include <ctype.h>
#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include "Objects/ObjectsRequirements.h"
#include "Scanning/ActorScanning.h"
#include <stdbool.h>
#include "Utility/String.h"

static bool isValidName(StringView name);
static bool isValidYearOfBirth(int yearOfBirth);

Actor scanActorFromStdin(void) {

    Actor result;

    printString("Podaj imie aktora (zgodne z zasadami wprowadzania danych): ");
    readStringIf(result.name, isValidName);

    printString("Podaj nazwisko: ");
    readStringIf(result.lastName, isValidName);

    printString("Podaj rok urodzenia aktora: ");
    result.yearOfBirth = readIntegerIf(isValidYearOfBirth);

    return result;

}

static bool isValidName(StringView name) {

    bool isThisBeginOfName = true;

    for(const char* it = name; *it != '\0'; ++it) {

        if(isThisBeginOfName) {

            if(isupper(*it) == 0) {
                return false;
            } else {
                isThisBeginOfName = false;
                continue;
            }

        }

        if(*it == '-') {
            isThisBeginOfName = true;
            continue;
        }

        if(islower(*it) == 0) {
            return false;
        }

    }

    return isThisBeginOfName == false;

}

static bool isValidYearOfBirth(int yearOfBirth) {
    return yearOfBirth >= MIN_ACTOR_YEAR_OF_BIRTH && yearOfBirth <= MAX_ACTOR_YEAR_OF_BIRTH;
}
