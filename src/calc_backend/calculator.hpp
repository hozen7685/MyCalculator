/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calculator.hpp
 *
 *  @brief   
 *
 *=============================================================================
 *  Revision History
 *  Version     Date        Author      Content
 *  -------     ----------  ---------   ---------------------------------------
 *  V1.00       2024/10/19  caohozen      Create.
 *
 *****************************************************************************/
#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__
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

static void update_left(char l);
static void update_right(char l);
static void res_oper_proc(char op);
static void update_oper(char op);
static int8_t calc_left_and_right(void);
static void update_left_and_operator(char op);
static void update_right_and_operator(char op);


extern char g_history_buffer[WORDS_MAX];
extern char g_current_buffer[WORDS_MAX];
extern void calc_input_proc(char value, input_type_t type);
#endif /* __CALCULATOR_HPP__ */
