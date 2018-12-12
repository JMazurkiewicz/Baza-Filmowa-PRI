#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "UserInterface/Logo.h"
#include "UserInterface/MenuPlayer.h"

static void displayMenu(StringView content);

int playMenu(const MenuData* data) {

    displayMenu(data->content);

    printString("Podaj numer opcji: ");
    return scanIntegerFromRange(1, data->maxOptionValue);

}

void displayMenu(StringView content) {

    clearConsole();
    displayLogo();
    puts(content);

}
