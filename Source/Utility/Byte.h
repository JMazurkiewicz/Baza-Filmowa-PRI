#pragma once

#include "System.h"

typedef unsigned char Byte;

#if defined(SYSTEM_WINDOWS)
#  define LITTLE_ENDIAN
#elif defined(__BYTE_ORDER__)
#  if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#    define LITTLE_ENDIAN
#  elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#    define BIG_ENDIAN
#  else
#    error Unexpected byte order.
#  endif
#else
#  error Unsupported compiler.
#endif
