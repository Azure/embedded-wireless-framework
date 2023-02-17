#ifndef __CC_H__
#define __CC_H__

#include <stdint.h>

#define BYTE_ORDER LITTLE_ENDIAN


/* define compiler specific symbols */
#if defined (__ICCARM__)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT 
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_USE_INCLUDES

#elif defined (__GNUC__)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT __attribute__ ((__packed__))
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x
#else

#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_STRUCT 
#define PACK_STRUCT_BEGIN   \
   __pragma(pack(push, 1))
#define PACK_STRUCT_END   \
     __pragma(pack(pop))
#endif

#endif /* __CC_H__ */
