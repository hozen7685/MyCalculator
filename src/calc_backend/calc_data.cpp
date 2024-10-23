/******************************************************************************
 *  Copyright 2024
 *
 *  @file    calc_data.cpp
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

/******************************************************************************
 *
 * INCLUDES
 *
 *****************************************************************************/
#include "calc_data.hpp"
#include <stdio.h>
#include <cmath>

int32_t cache_l = 0;
int32_t cache_r = 0;
int32_t result = 0;
char operation = 0;
char g_history_buffer[WORDS_MAX] = "\n";
char g_current_buffer[WORDS_MAX] = "0";

/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void update_left(char l)
{
    if (cache_l < (INT32_MAX / 10)) {
        cache_l = 10 * cache_l + l;
    }
}

void update_right(char l)
{
    if (cache_r < (INT32_MAX / 10)) {
        cache_r = 10 * cache_r + l;
    }
}

int8_t calc_left_and_right(void)
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

/* - End Of File - */

