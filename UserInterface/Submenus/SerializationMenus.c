#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "Lists/Database.h"
#include "UserInterface/Submenus/SerializationMenus.h"

void newDatabase(Database* database) {

    saveDatabaseIfModified(database, "Czy chcesz zapisac baze przed utworzeniem nowej");
    freeDatabase(database);

}

void saveDatabaseIfModified(Database* database, StringView question) {

    if(database->isModified) {

        printString(question);
        printString(" (T/N): ");

        if(scanBoolean()) {
            saveDatabaseToFile(database);
        }

    }

}

void saveDatabaseToFile(Database* database) {

    if(database->isModified) {

        if(strIsEmpty(database->filePath)) {

            puts("Twoja baza nie zostala jeszcze zapisana.");
            saveDatabaseAs(database);

        } else {

            serializeDatabase(database->filePath, database);
            database->isModified = false;

        }

    }

}

void saveDatabaseAs(Database* database) {

    printString("Podaj nazwe pliku dla twojej bazy: ");
    String filePath;
    scanLine(filePath);
    strcat(filePath, DATABASE_FILE_EXTENSION);

    strcpy(database->filePath, filePath);
    serializeDatabase(database->filePath, database);
    database->isModified = false;

}
