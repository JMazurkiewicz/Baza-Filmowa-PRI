#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include "UserInterface/Logo.h"
#include "UserInterface/MenuPlayer.h"

static void displayMenu(StringView content);

int playMenu(const MenuData* data) {

    displayMenu(data->content);

    printString("Podaj numer opcji: ");
    return scanIntegerIf(data->inputValidator);

}

void displayMenu(StringView content) {

    clearConsole();
    displayLogo();

    puts(content);

}
