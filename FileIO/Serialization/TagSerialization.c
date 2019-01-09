#include "FileIO/Serialization/BasicSerialization.h"
#include "FileIO/Serialization/TagSerialization.h"
#include "Utility/Date.h"

void startListSerialization(DatabaseFile* file) {
    serializeByte(file, '\x01');
}

void startObjectSerialization(DatabaseFile* file) {
    serializeByte(file, '\x02');
}

void endObjectSerialization(DatabaseFile* file) {
    serializeByte(file, '\x03');
}

void endListSerialization(DatabaseFile* file) {
    serializeByte(file, '\x04');
}

void serializeHeader(DatabaseFile* file) {

    DatabaseFile helper = {file->handle, 0};
    serializeByte(&helper, file->key);

    Date now;
    currentDate(&now);
    serializeInt64(file, dateToLongLong(&now));

}
