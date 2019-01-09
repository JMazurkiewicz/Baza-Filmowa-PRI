#pragma once

#include "CommonIO/BasicIO.h"
#include "Utility/Byte.h"

typedef struct DatabaseFile {

    FILE* handle;
    Byte key;

} DatabaseFile;
