/******************************************************************************
 *  Copyright 2024
 *
 *  @file    left_state.cpp
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
#include "left_state.hpp"
#include "oper_state.hpp"
#include "result_state.hpp"
#include "clear_state.hpp"
#include "../calc_data.hpp"
#include <stdio.h>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void left_state_c::input_state_proc(char value)
{
    switch (value)
    {
    case NUM_0:
    case NUM_1:
    case NUM_2:
    case NUM_3:
    case NUM_4:
    case NUM_5:
    case NUM_6:
    case NUM_7:
    case NUM_8:
    case NUM_9:
        update_left(value);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_l);
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        operation = value;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, operation);
        this->calculator_->trans_to(new oper_state_c());
        break;
    case RESULT:
        result = cache_l;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", cache_l, value);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        this->calculator_->trans_to(new result_state_c());
        break;
    case CLEAR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        this->calculator_->trans_to(new clear_state_c());
        break;
    default:
        break;
    }
}
/* - End Of File - */
