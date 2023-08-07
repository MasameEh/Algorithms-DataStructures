#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#define ZERO 0

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef float float32;
typedef float float64;

typedef enum ret_status{
    R_NOK,
    R_OK
}return_status_t;

#endif 