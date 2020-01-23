#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/FileSystem.h"
#include "UserInterface/Logo.h"
#include "UserInterface/Submenus/DatabaseDeletionMenu.h"

static size_t MAX_DATABASE_FILE_COUNT = 16;

static void displayMenu(String* fileNames, size_t databaseFileCount);
static int scanUsersChoice(size_t databaseFileCount);
static bool isInputValidForDatabaseDeletion(int input, size_t databaseFileCount);
static bool isUserSure(StringView fileName);
static void deletionError(void);

void databaseDeletionMenu() {

    String fileNames[MAX_DATABASE_FILE_COUNT];
    const size_t databaseFileCount = getNamesOfDatabaseFiles(fileNames, MAX_DATABASE_FILE_COUNT);

    displayMenu(fileNames, databaseFileCount);
    const int input = scanUsersChoice(databaseFileCount);

    if(isInputValidForDatabaseDeletion(input, databaseFileCount) && isUserSure(fileNames[input-1])) {

        if(remove(fileNames[input-1]) != 0) {
            deletionError();
        }

    }

}

void displayMenu(String* fileNames, size_t databaseFileCount) {

    clearConsole();
    displayLogo();

    puts("Usun baze danych (lub zrezygnuj):");

    int i = 0;
    for(; i < databaseFileCount; ++i) {
        printf("%d) %s\n", i+1, fileNames[i]);
    }

    printf("%d) Rezygnuje...\n", i+1);

}

int scanUsersChoice(size_t databaseFileCount) {
    printString("\nPodaj numer pliku, ktory chcesz usunac: ");
    return scanIntegerFromRange(1, databaseFileCount+1);
}

bool isInputValidForDatabaseDeletion(int input, size_t databaseFileCount) {
    return 1 <= input && input <= databaseFileCount;
}

bool isUserSure(StringView fileName) {
    printf("Czy na pewno chcesz usunac baze \"%s\" (T/N): ", fileName);
    return scanBoolean();
}

static void deletionError(void) {
    puts("Usuwanie bazy nie powiodlo sie.");
    waitForEnter();
}
