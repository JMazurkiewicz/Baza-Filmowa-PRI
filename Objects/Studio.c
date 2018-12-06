#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Objects/Studio.h"
#include "Utility/MovieLimits.h"

bool hasStudioThisName(const Studio* studio, StringView name) {
    return strcmp(studio->name, name) == 0;
}

void scanStudiosName(String name) {
    printString("Podaj nazwe studia: ");
    getLine(name);
    trimWhitespace(name);
}

void scanStudio(Studio* studio) {

    scanStudiosName(studio->name);

    printString("Podaj adres studia: ");
    getLine(studio->address);
    trimWhitespace(studio->address);

    printString("Podaj kontakt ze studie (np. adres e-mail): ");
    getLine(studio->contact);
    trimWhitespace(studio->contact);

    printString("Podaj rok zalozenia studia: ");
    studio->yearOfFounding =
        scanIntegerFromRange(MIN_STUDIOS_YEAR_OF_FOUNDING, MAX_STUDIOS_YEAR_OF_FOUNDING);

}

void printStudio(const Studio* studio) {
    printf("Nazwa studia: %s\n", studio->name);
    printf("Adres studia: %s\n", studio->address);
    printf("Kontakt ze studiem: %s\n", studio->contact);
    printf("Rok zalozenia: %d\n", studio->yearOfFounding);
}
