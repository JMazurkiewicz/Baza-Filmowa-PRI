#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Deserialization.h"
#include "FileIO/FileSystem.h"
#include "Lists/Database.h"
#include "UserInterface/Logo.h"
#include "UserInterface/Submenus/Backup.h"

void backup(Database* database) {

    clearConsole();
    displayLogo();

    if(doesFileExist(BACKUP_FILE_NAME)) {

        printString("Dostepna jest kopia zapasowa poprzedniej bazy.\nCzy chcialbys z niej skorzystac (T/N): ");

        if(scanBoolean()) {
            freeDatabase(database);

            if(deserializeDatabase(BACKUP_FILE_NAME, database)) {
                database->isModified = true;
                database->fileName[0] = '\0';
            }

        }

        remove(BACKUP_FILE_NAME);

    }

}
