/******************************************************************************
 *  Copyright 2024
 *
 *  @file    error_state.cpp
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
#include "error_state.hpp"
#include "left_state.hpp"
#include "result_state.hpp"
#include "../calc_data.hpp"
#include <stdio.h>
/******************************************************************************
 *
 * FUNCTIONS
 *
 *****************************************************************************/
void error_state_c::input_state_proc(char value)
{
    switch (value)
    {
    case NUMBER:
        cache_l = 0;
        cache_r = 0;
        update_left(value);
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        this->calculator_->trans_to(new left_state_c());
        break;
    case OPERATOR:
        cache_l = 0;
        cache_r = 0;
        result = 0;
        snprintf(g_history_buffer, (WORDS_MAX - 1), "\n");
        snprintf(g_current_buffer, (WORDS_MAX - 1), "%d", result);
        this->calculator_->trans_to(new result_state_c());
        break;
    default:
        break;
    }
}
/* - End Of File - */
