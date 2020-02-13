#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "Lists/Database.h"
#include "SerializationMenus.h"

void newDatabase(Database* database) {
    saveDatabaseIfModified(database, "Czy chcesz zapisac baze przed utworzeniem nowej");
    freeDatabase(database);
}

void saveDatabaseIfModified(Database* database, StringView question) {

    if(database->isDatabaseModified) {

        printf("%s (T/N): ", question);

        if(scanBoolean()) {
            saveDatabaseToFile(database);
        }

    }

}

void saveDatabaseToFile(Database* database) {

    if(database->isDatabaseModified) {

        if(strIsEmpty(database->fileName)) {
            puts("Twoja baza nie zostala jeszcze zapisana.");
            saveDatabaseAs(database);
        } else {
            serializeDatabase(database->fileName, database);
            database->isDatabaseModified = false;
        }

    }

}

void saveDatabaseAs(Database* database) {

    printString("Podaj nazwe pliku dla twojej bazy: ");
    String fileName;
    scanLine(fileName);
    strcat(fileName, DATABASE_FILE_EXTENSION);

    strcpy(database->fileName, fileName);
    serializeDatabase(database->fileName, database);
    database->isDatabaseModified = false;

}

void saveAtExit(Database* database) {

    if(database->isDatabaseModified) {

        printString("Czy chcesz zapisac baze przed opuszczeniem aplikacji (T/N): ");

        if(!scanBoolean()) {
            strcpy(database->fileName, BACKUP_FILE_NAME);
        }

        saveDatabaseToFile(database);

    }

}
