/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calculator.cpp
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

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "calculator.hpp"
#include <stdio.h>
#include <cmath>

static int32_t cache_l = 0;
static int32_t cache_r = 0;
static int32_t result = 0;
static char operation = 0;
static calc_state_t state = RESULT_S;
char g_history_buffer[WORDS_MAX] = "\n";
char g_current_buffer[WORDS_MAX] = "0";
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
static void update_left(char l)
{
    if (cache_l < (INT32_MAX / 10)) {
        cache_l = 10 * cache_l + l;
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_l);
    }
}

static void update_right(char l)
{
    if (cache_r < (INT32_MAX / 10)) {
        cache_r = 10 * cache_r + l;
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_r);
    }
}

static void res_oper_proc(char op)
{
    switch (op)
    {
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        cache_l = result;
        operation = op;
        cache_r = result;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", result, operation);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = OPER_S;
        break;
    case RESULT:
        cache_l = result;
        if (0 == calc_left_and_right()) {
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c %d %c\n",
                cache_l, operation, cache_r, op);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            state = ERROR_S;
        }
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n", result);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    default:
        break;
    }
}

static void update_oper(char op)
{
    switch (op)
    {
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        operation = op;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, operation);
        break;
    case RESULT:
        cache_r = cache_l;
        if(0 == calc_left_and_right()) {
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c %d %c\n",
                cache_l, operation, cache_l, op);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            state = RESULT_S;
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            state = ERROR_S;
        }
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n", result);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    default:
        break;
    }
}

static int8_t calc_left_and_right(void)
{
    int8_t ret = -1;
    switch (operation)
    {
    case PLUS:
        if ((INT32_MAX - cache_l) > cache_r) {
            result = cache_l + cache_r;
            ret = 0;
        }
        break;
    case MINUS:
        result = cache_l - cache_r;
        ret = 0;
        break;
    case MULTIPLY:
        if ((INT32_MAX / abs(cache_l)) > abs(cache_r)) {
            result = cache_l * cache_r;
            ret = 0;
        }
        break;
    case DIVIDE:
        if (0 != cache_r) {
            result = cache_l / cache_r;
            ret = 0;
        }
        break;
    default:
        break;
    }
    return ret;
}

static void update_left_and_operator(char op)
{
    switch (op)
    {
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        operation = op;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, operation);
        state = OPER_S;
        break;
    case RESULT:
        result = cache_l;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, op);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    default:
        break;
    }
}

static void update_right_and_operator(char op)
{
    switch (op)
    {
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        if (0 == calc_left_and_right()) {
            operation = op;
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", result, operation);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            cache_l = result;
            state = OPER_S;
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            state = ERROR_S;
        }
        break;
    case RESULT:
        if(0 == calc_left_and_right()) {
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c %d %c\n",
                cache_l, operation, cache_r, op);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            state = RESULT_S;
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            state = ERROR_S;
        }
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        state = RESULT_S;
        break;
    default:
        break;
    }
}

void calc_input_proc(char value, input_type_t type)
{
    switch (state)
    {
    case LEFT_S:
        switch (type)
        {
        case NUMBER:
            update_left(value);
            break;
        case OPERATOR:
            update_left_and_operator(value);
            break;
        default:
            break;
        }
        break;
    case OPER_S:
        switch (type)
        {
        case NUMBER:
            cache_r = 0;
            update_right(value);
            state = RIGHT_S;
            break;
        case OPERATOR:
            update_oper(value);
            break;
        default:
            break;
        }
        break;
    case RIGHT_S:
        switch (type)
        {
        case NUMBER:
            update_right(value);
            break;
        case OPERATOR:
            update_right_and_operator(value);
            break;
        default:
            break;
        }
        break;
    case RESULT_S:
        switch (type)
        {
        case NUMBER:
            cache_l = 0;
            cache_r = 0;
            update_left(value);
            state = LEFT_S;
            break;
        case OPERATOR:
            res_oper_proc(value);
            break;
        default:
            break;
        }
        break;
    case ERROR_S:
        switch (type)
        {
        case NUMBER:
            cache_l = 0;
            cache_r = 0;
            update_left(value);
            snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
            state = LEFT_S;
            break;
        case OPERATOR:
            cache_l = 0;
            cache_r = 0;
            result = 0;
            snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            state = RESULT_S;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    printf("LEFT:%d\nOPER:%c\nRIGHT:%d\nRES:%d\nSTATE:%d\n---------------\n",
         cache_l, operation, cache_r, result, state);
}
/* - End Of File - */
