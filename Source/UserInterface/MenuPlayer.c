#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "Logo.h"
#include "MenuPlayer.h"

int playMenu(const MenuData* menuData) {

    clearConsole();
    displayLogo();
    puts(menuData->content);

    printString("Podaj numer opcji: ");
    return scanBoundedInteger(1, menuData->maxOptionValue);

}
