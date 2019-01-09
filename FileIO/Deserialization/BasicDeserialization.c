#include "FileIO/Deserialization/BasicDeserialization.h"

Byte deserializeByte(DatabaseFile* file) {
    const Byte byte = fgetc(file->handle);
    return byte - file->key;
}

void deserializeInteger(DatabaseFile* file, Byte* firstByte, size_t width) {

#if defined(LITTLE_ENDIAN)

    for(int i = width; i--; ) {
        *firstByte++ = deserializeByte(file);
    }

#elif defined(BIG_ENDIAN)

    firstByte += width;

    for(int i = width; i--; ) {
        *--firstByte = deserializeByte(file);
    }

#endif

}

int32_t deserializeInt32(DatabaseFile* file) {
    int32_t result;
    deserializeInteger(file, (Byte*)&result, 4);
    return result;
}

int64_t deserializeInt64(DatabaseFile* file) {
    int64_t result;
    deserializeInteger(file, (Byte*)&result, 8);
    return result;
}

void* deserializeAddress(DatabaseFile* file) {
    intptr_t result = (intptr_t)deserializeInt64(file);
    return (void*)result;
}

void deserializeString(DatabaseFile* file, String string) {

    Byte length = deserializeByte(file);

    while(length--) {
        *string++ = deserializeByte(file);
    }

    *string = '\0';

}
