#include "CommonIO/BasicIO.h"
#include "UserInterface/Logo.h"
#include "UserInterface/Submenus/Instructions.h"
#include "Utility/String.h"

static const StringView INSTRUCTIONS = {
    "Aplikacja sluzy do budowania bazy danych filmow, aktorow i studiow nagraniowych\n"
    "na nastepujacych zasadach:\n"
    "1) Jeden aktor moze wystepowac w wielu filmach\n"
    "2) Jeden film moze miec wielu aktorow\n"
    "3) Jeden film ma dokladnie jedno studio nagraniowe\n"
    "4) Studio nagraniowe moze realizowac wiele filmow\n"
    "\n"
    "Inne zasady:\n"
    "1) Wszystkie teksty wprowadzane w aplikacji moga miec maksymalnie 128 znakow\n"
    "2) Imiona zaczynamy wielka litera, kazda kolejna litera musi byc mala\n"
    "3) Imiona moga byc wieloczlonowe (kolejne czlony oddzielamy jedna spacja)\n"
    "4) W aplikacji operujemy datami od 1888 do 2018 roku\n"
    "5) Najdluzszy film moze miec 14400 minut, najkrotszy jedna\n"
    "\n"
    "Zycze milego korzystania z aplikacji.\n"
};

void instructions(void) {

    clearConsole();
    displayLogo();

    puts(INSTRUCTIONS);
    waitForEnter();

}
