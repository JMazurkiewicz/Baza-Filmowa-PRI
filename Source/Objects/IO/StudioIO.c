#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Objects/Studio.h"
#include "Utility/MovieLimits.h"

void scanStudiosName(String name) {

    printString("Podaj nazwe studia: ");
    scanLine(name);
    strTrimWhitespace(name);

}

void scanStudiosIdentifier(Studio* studio) {
    scanStudiosName(studio->name);
}

void scanStudiosData(Studio* studio) {

    printString("Podaj adres studia: ");
    scanLine(studio->address);
    strTrimWhitespace(studio->address);

    printString("Podaj kontakt ze studiem (np. adres e-mail): ");
    scanLine(studio->contact);
    strTrimWhitespace(studio->contact);

    printString("Podaj rok zalozenia studia: ");
    studio->yearOfFounding = scanIntegerFromRange(MIN_STUDIOS_YEAR_OF_FOUNDING, MAX_STUDIOS_YEAR_OF_FOUNDING);

}

void printStudiosName(const Studio* studio) {
    printf("%s", studio->name);
}

void printStudio(const Studio* studio) {

    printString("Nazwa studia: ");
    printStudiosName(studio);
    newLine();

    printf("Adres studia: %s\n", studio->address);
    printf("Kontakt ze studiem: %s\n", studio->contact);
    printf("Rok zalozenia: %d\n", studio->yearOfFounding);

}
