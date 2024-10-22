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
#define WORDS_MAX   64
#define INT32_MAX   2147483647

typedef enum {
    NUMBER,
    OPERATOR
} input_type_t;

typedef enum {
    LEFT_S,
    OPER_S,
    RIGHT_S,
    RESULT_S,
    ERROR_S
} calc_state_t;

extern int32_t cache_l;
extern int32_t cache_r;
extern int32_t result;
extern char operation;
extern calc_state_t state;
extern char g_history_buffer[WORDS_MAX];
extern char g_current_buffer[WORDS_MAX];

extern void update_left(char l);
extern void update_right(char l);
extern void res_oper_proc(char op);
extern void update_oper(char op);
extern int8_t calc_left_and_right(void);
extern void update_left_and_operator(char op);
extern void update_right_and_operator(char op);

#endif /* __CALC_DATA_HPP__ */
