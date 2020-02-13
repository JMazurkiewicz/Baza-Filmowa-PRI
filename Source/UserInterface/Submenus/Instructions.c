#include "CommonIO/BasicIO.h"
#include "UserInterface/Logo.h"
#include "Utility/String.h"

static const StringView INSTRUCTIONS = {
    "Aplikacja sluzy do budowania bazy danych filmow, aktorow i studiow nagraniowych\n"
    "na nastepujacych zasadach:\n"
    "1) Jeden aktor moze wystepowac w wielu filmach\n"
    "2) W bazie nie moze byc dwoch aktorow z takim samym imieniem i nazwiskiem\n"
    "3) Jeden film moze miec wielu aktorow\n"
    "4) Jeden film ma dokladnie jedno studio nagraniowe\n"
    "5) W bazie nie moga pojawic sie dwa filmy o takich samych tytulach\n"
    "6) Studio nagraniowe moze realizowac wiele filmow\n"
    "7) W bazie nie moga pojawic sie dwa studia o takich samych nazwach\n"
    "\n"
    "Inne zasady:\n"
    "1) Wszystkie teksty wprowadzane w aplikacji moga miec maksymalnie 128 znakow\n"
    "2) Wszystkie wprowadzane dane zatwierdzamy enterem\n"
    "3) Imiona zaczynamy wielka litera, kazda kolejna litera musi byc mala\n"
    "4) Imiona moga byc wieloczlonowe (kolejne czlony oddzielamy jedna spacja)\n"
    "5) W aplikacji operujemy datami od 1888 do 2019 roku\n"
    "6) Najdluzszy film moze miec 14400 minut, najkrotszy jedna\n"
    "\n"
    "Zycze milego korzystania z aplikacji.\n"
};

void instructions(void) {

    clearConsole();
    displayLogo();

    puts(INSTRUCTIONS);
    waitForEnter();

}
