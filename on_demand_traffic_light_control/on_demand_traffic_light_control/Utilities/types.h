/*
 * types.h
 *
 * Created: 12/7/2022 9:58:24 PM
 *  Author: Adnan
 */ 



#ifndef TYPES_H_
#define TYPES_H_

/* PRE_PROCESSOR MACROS */

#define CPU_TYPE_64 64
#define CPU_TYPE_32 32
#define CPU_TYPE_16 16
#define CPU_TYPE_8 8

#define CPU_TYPE (CPU_TYPE_64)

/*-----------------------------------*/

#if (CPU_TYPE == (CPU_TYPE_64))

typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t_m;
typedef unsigned int uint32_t_m;
typedef unsigned long long uint64_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;
typedef signed long long sint64_t;

typedef float float32_t;
typedef double float64_t;

#elif (CPU_TYPE == (CPU_TYPE_32))

typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t_m;
typedef unsigned long uint32_t_m;
typedef unsigned long long uint64_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;

typedef float float32_t;
typedef double float64_t;

#elif (CPU_TYPE == (CPU_TYPE_16))

typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t_m;
typedef unsigned long uint32_t_m;
typedef unsigned long long uint64_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;

typedef float float32_t;
typedef double float64_t;

#endif

#endif /* TYP_ES_H_ */