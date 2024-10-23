/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calc_data.hpp
 *
 *  @brief
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/22  caohz      Create.
 *
 *****************************************************************************/
#ifndef __CALC_DATA_HPP__
#define __CALC_DATA_HPP__

#include <cstdint>

#define PLUS        '+'
#define MINUS       '-'
#define MULTIPLY    '*'
#define DIVIDE      '/'
#define RESULT      '='
#define CLEAR       'c'
#define NUM_0       (char)0
#define NUM_1       (char)1
#define NUM_2       (char)2
#define NUM_3       (char)3
#define NUM_4       (char)4
#define NUM_5       (char)5
#define NUM_6       (char)6
#define NUM_7       (char)7
#define NUM_8       (char)8
#define NUM_9       (char)9
#define WORDS_MAX   64
#define INT32_MAX   2147483647

extern int32_t cache_l;
extern int32_t cache_r;
extern int32_t result;
extern char operation;
extern char g_history_buffer[WORDS_MAX];
extern char g_current_buffer[WORDS_MAX];

extern void update_left(char l);
extern void update_right(char l);
extern int8_t calc_left_and_right(void);

#endif /* __CALC_DATA_HPP__ */
