/******************************************************************************
 *  Copyright 2024
 *
 *  @file    right_state.cpp
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
#include "right_state.hpp"
#include "oper_state.hpp"
#include "error_state.hpp"
#include "result_state.hpp"
#include "clear_state.hpp"
#include "../calc_data.hpp"
#include <stdio.h>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void right_state_c::input_state_proc(char value)
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
        update_right(value);
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", cache_r);
        break;
    case PLUS:
    case MINUS:
    case MULTIPLY:
    case DIVIDE:
        if (0 == calc_left_and_right()) {
            cache_l = result;
            operation = value;
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c\n", result, operation);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            this->calculator_->trans_to(new oper_state_c());
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            this->calculator_->trans_to(new error_state_c());
        }
        break;
    case RESULT:
        if(0 == calc_left_and_right()) {
            snprintf(g_history_buffer, (WORDS_MAX - 1), "%d %c %d %c\n",
                cache_l, operation, cache_r, value);
            snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
            this->calculator_->trans_to(new result_state_c());
        } else {
            snprintf(g_current_buffer, (WORDS_MAX - 1), "error overflow");
            this->calculator_->trans_to(new error_state_c());
        }
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
