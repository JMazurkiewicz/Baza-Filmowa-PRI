#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "Lists/Database.h"
#include "UserInterface/Submenus/SerializationMenus.h"

void newDatabase(Database* database) {}

void saveDatabaseToFile(Database* database) {

    if(database->isModified) {

        if(strIsEmpty(database->fileName)) {

            saveDatabaseAs(database);

        } else {

            puts("Twoja baza nie zostala jeszcze zapisana.");
            serializeDatabase(database->fileName, database);

        }

    }

}

void saveDatabaseAs(Database* database) {

    printString("Podaj nazwe pliku dla twojej bazy: ");
    String fileName;
    scanLine(fileName);

    serializeDatabase(fileName, database);

}

void saveAtExit(Database* database) {

    printString("Czy chcesz zapisac baze przed opuszczeniem aplikacji (T/N): ");
    if(scanBoolean()) {
        saveDatabaseToFile(database);
    }

}

void loadDatabaseFromFile(Database* database) {
    // @todo
}
