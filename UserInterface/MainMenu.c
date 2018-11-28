#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdbool.h>
#include "UserInterface/Logo.h"
#include "UserInterface/MainMenu.h"
#include "Utility/System.h"

static void displayMenu();
static bool isValidInput(char input);

MainMenuResult MainMenu(void) {

    displayMenu();

    printString("Podaj numer opcji: ");
    const char input = readSingleCharIf(isValidInput);

    return (MainMenuResult)input;

}

void displayMenu() {

    clearConsole();
    displayBigLogo();

    puts("Menu glowne:");
    puts("1) Dodaj...");
    puts("2) Usun...");
    puts("3) Wypisz dane o...");
    puts("4) Sortuj...");
    puts("5) Zapisz zmiany do pliku [niedostepne]");
    puts("6) Wczytaj poprzedni zapis [niedostepne]");
    puts("7) Wyjscie");

    newLine();

}

bool isValidInput(char input) {
    return input >= '1' && input <= '7';
}
